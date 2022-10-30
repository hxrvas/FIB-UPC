#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

#define UNDEF -1
#define TRUE 1
#define FALSE 0
#define REDUCE_STEPS 10

uint numVars;
uint numClauses;
vector<vector<int> > clauses;
vector<int> model;
vector<int> modelStack;
uint indexOfNextLitToPropagate;
uint decisionLevel;

//Improvement of propagation
vector<vector<uint>> litOccurList;
vector<vector<uint>> negLitOccurList;

//Improvement of heuristic
vector<float> varActivity;
int conflicts;


void readClauses( ){
  // Skip comments
  char c = cin.get();
  while (c == 'c') {
    while (c != '\n') c = cin.get();
    c = cin.get();
  }  
  // Read "cnf numVars numClauses"
  string aux;
  cin >> aux >> numVars >> numClauses;
  clauses.resize(numClauses);  
  litOccurList.resize(numVars+1);
  negLitOccurList.resize(numVars+1);
  varActivity.resize(numVars+1);
  // Read clauses
  for (uint i = 0; i < numClauses; ++i) {
    int lit;
    while (cin >> lit and lit != 0) {
     
      if (lit > 0) {
        litOccurList[lit].push_back(i);
        ++varActivity[lit];
      }
      else {
        negLitOccurList[-lit].push_back(i);
        ++varActivity[-lit];
      } 
      clauses[i].push_back(lit);
    } 
  } 

  conflicts = 0;   
}



int currentValueInModel(int lit){
  if (lit >= 0) return model[lit];
  else {
    if (model[-lit] == UNDEF) return UNDEF;
    else return 1 - model[-lit];
  }
}


void setLiteralToTrue(int lit){
  modelStack.push_back(lit);
  if (lit > 0) model[lit] = TRUE;
  else model[-lit] = FALSE;		
}


bool propagateGivesConflict ( ) {
  while ( indexOfNextLitToPropagate < modelStack.size() ) {

    int lit = modelStack[indexOfNextLitToPropagate];
    ++indexOfNextLitToPropagate;

    vector<uint>* litClauses;

    //We take the reference to the corresponding occur list
    if (lit > 0) {
      litClauses = &negLitOccurList[lit]; 
    }
    else {
      litClauses = &litOccurList[-lit]; 
    }

    for (uint i = 0; i < litClauses->size(); ++i) {
      bool someLitTrue = false;
      int numUndefs = 0;
      int lastLitUndef = 0;
      int clauseIndex = (*litClauses)[i]; 
      for (uint k = 0; not someLitTrue and k < clauses[clauseIndex].size(); ++k){
        int val = currentValueInModel(clauses[clauseIndex][k]);
        if (val == TRUE) someLitTrue = true;
        else if (val == UNDEF){ ++numUndefs; lastLitUndef = clauses[clauseIndex][k]; }
      }

      if (not someLitTrue and numUndefs == 0) {
        
        //Record the activity
        ++varActivity[abs(lit)];

        //If we reach reduce steps, reduce activity
        ++conflicts;
        if (conflicts % (REDUCE_STEPS*numVars) == 0) {
          for (uint v = 1; v <= numVars; ++v) varActivity[v] /= 2;
        }

        return true; // conflict! all lits false
      } 

      else if (not someLitTrue and numUndefs == 1) setLiteralToTrue(lastLitUndef);

    }

  }
  return false;
}


void backtrack(){
  uint i = modelStack.size() -1;
  int lit = 0;
  while (modelStack[i] != 0){ // 0 is the DL mark
    lit = modelStack[i];
    model[abs(lit)] = UNDEF;
    modelStack.pop_back();
    --i;
  }
  // at this point, lit is the last decision
  modelStack.pop_back(); // remove the DL mark
  --decisionLevel;
  indexOfNextLitToPropagate = modelStack.size();
  setLiteralToTrue(-lit);  // reverse last decision
}


// Heuristic for finding the next decision literal:
int getNextDecisionLiteral(){
  float max = 0;
  int bestLit = 0;

  for (uint i = 1; i <= numVars; ++i) {
    if (model[i] == UNDEF) {
      if (varActivity[i] > max) {
        max = varActivity[i];
        bestLit = i;
      }
    }  
  }
  return bestLit; // returns 0 when all literals are defined
}

void checkmodel(){
  for (uint i = 0; i < numClauses; ++i){
    bool someTrue = false;
    for (uint j = 0; not someTrue and j < clauses[i].size(); ++j)
      someTrue = (currentValueInModel(clauses[i][j]) == TRUE);
    if (not someTrue) {
      cout << "Error in model, clause is not satisfied:";
      for (uint j = 0; j < clauses[i].size(); ++j) cout << clauses[i][j] << " ";
      cout << endl;
      exit(1);
    }
  }  
}

int main(){ 
  readClauses(); // reads numVars, numClauses and clauses
  model.resize(numVars+1,UNDEF);
  indexOfNextLitToPropagate = 0;  
  decisionLevel = 0;
  
  // Take care of initial unit clauses, if any
  for (uint i = 0; i < numClauses; ++i)
    if (clauses[i].size() == 1) {
      int lit = clauses[i][0];
      int val = currentValueInModel(lit);
      if (val == FALSE) {cout << "UNSATISFIABLE" << endl; return 10;}
      else if (val == UNDEF) setLiteralToTrue(lit);
    }
  
  // DPLL algorithm
  while (true) {
    while ( propagateGivesConflict() ) {
      if ( decisionLevel == 0) { cout << "UNSATISFIABLE" << endl; return 10; }
      backtrack();
    }
    int decisionLit = getNextDecisionLiteral();
    if (decisionLit == 0) { checkmodel(); cout << "SATISFIABLE" << endl; return 20; }
    // start new decision level:
    modelStack.push_back(0);  // push mark indicating new DL
    ++indexOfNextLitToPropagate;
    ++decisionLevel;
    setLiteralToTrue(decisionLit);    // now push decisionLit on top of the mark
  }
}  
