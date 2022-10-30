
// Generated from Asl.g4 by ANTLR 4.7.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

antlrcpp::Any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      function();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(31);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::ParametersContext* AslParser::FunctionContext::parameters() {
  return getRuleContext<AslParser::ParametersContext>(0);
}

AslParser::FuncTypeContext* AslParser::FunctionContext::funcType() {
  return getRuleContext<AslParser::FuncTypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

antlrcpp::Any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(AslParser::FUNC);
    setState(34);
    match(AslParser::ID);
    setState(35);
    match(AslParser::T__0);
    setState(37);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(36);
      parameters();
    }
    setState(39);
    match(AslParser::T__1);
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__2) {
      setState(40);
      funcType();
    }
    setState(43);
    declarations();
    setState(44);
    statements();
    setState(45);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

AslParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::ParametersContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::ParametersContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeContext *> AslParser::ParametersContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::ParametersContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::ParametersContext::getRuleIndex() const {
  return AslParser::RuleParameters;
}

antlrcpp::Any AslParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ParametersContext* AslParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(AslParser::ID);
    setState(48);
    match(AslParser::T__2);
    setState(49);
    type();
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(50);
      match(AslParser::T__3);
      setState(51);
      match(AslParser::ID);
      setState(52);
      match(AslParser::T__2);
      setState(53);
      type();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

AslParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::BasicTypeContext* AslParser::FuncTypeContext::basicType() {
  return getRuleContext<AslParser::BasicTypeContext>(0);
}


size_t AslParser::FuncTypeContext::getRuleIndex() const {
  return AslParser::RuleFuncType;
}

antlrcpp::Any AslParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FuncTypeContext* AslParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleFuncType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(AslParser::T__2);
    setState(60);
    basicType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

antlrcpp::Any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(62);
      variable_decl();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

antlrcpp::Any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(AslParser::VAR);
    setState(69);
    match(AslParser::ID);
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__3) {
      setState(70);
      match(AslParser::T__3);
      setState(71);
      match(AslParser::ID);
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
    match(AslParser::T__2);
    setState(78);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TupleDeclContext ------------------------------------------------------------------

std::vector<AslParser::BasicTypeContext *> AslParser::TupleDeclContext::basicType() {
  return getRuleContexts<AslParser::BasicTypeContext>();
}

AslParser::BasicTypeContext* AslParser::TupleDeclContext::basicType(size_t i) {
  return getRuleContext<AslParser::BasicTypeContext>(i);
}

AslParser::TupleDeclContext::TupleDeclContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::TupleDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitTupleDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDeclContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ArrayDeclContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::ArrayDeclContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ArrayDeclContext::OF() {
  return getToken(AslParser::OF, 0);
}

AslParser::BasicTypeContext* AslParser::ArrayDeclContext::basicType() {
  return getRuleContext<AslParser::BasicTypeContext>(0);
}

AslParser::ArrayDeclContext::ArrayDeclContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ArrayDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArrayDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BasicContext ------------------------------------------------------------------

AslParser::BasicTypeContext* AslParser::BasicContext::basicType() {
  return getRuleContext<AslParser::BasicTypeContext>(0);
}

AslParser::BasicContext::BasicContext(TypeContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::BasicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasic(this);
  else
    return visitor->visitChildren(this);
}
AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::ARRAY: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<AslParser::ArrayDeclContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(80);
        match(AslParser::ARRAY);
        setState(81);
        match(AslParser::T__4);
        setState(82);
        match(AslParser::INTVAL);
        setState(83);
        match(AslParser::T__5);
        setState(84);
        match(AslParser::OF);
        setState(85);
        basicType();
        break;
      }

      case AslParser::T__6: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<AslParser::TupleDeclContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(86);
        match(AslParser::T__6);
        setState(87);
        basicType();
        setState(92);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__3) {
          setState(88);
          match(AslParser::T__3);
          setState(89);
          basicType();
          setState(94);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(95);
        match(AslParser::T__7);
        break;
      }

      case AslParser::INT:
      case AslParser::BOOL:
      case AslParser::FLOAT:
      case AslParser::CHAR: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<AslParser::BasicContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(97);
        basicType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

AslParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::BasicTypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::BasicTypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::BasicTypeContext::getRuleIndex() const {
  return AslParser::RuleBasicType;
}

antlrcpp::Any AslParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::BasicTypeContext* AslParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleBasicType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

antlrcpp::Any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::PACK)
      | (1ULL << AslParser::UNPACK)
      | (1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(102);
      statement();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProcCallParamsContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallParamsContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallParamsContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallParamsContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ProcCallParamsContext::ProcCallParamsContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ProcCallParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCallParams(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProcCallNoParamsContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallNoParamsContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ProcCallNoParamsContext::ProcCallNoParamsContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ProcCallNoParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCallNoParams(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnpackStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::UnpackStmtContext::UNPACK() {
  return getToken(AslParser::UNPACK, 0);
}

AslParser::IdentContext* AslParser::UnpackStmtContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::UnpackStmtContext::INTO() {
  return getToken(AslParser::INTO, 0);
}

std::vector<AslParser::ExprContext *> AslParser::UnpackStmtContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::UnpackStmtContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::UnpackStmtContext::UnpackStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::UnpackStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnpackStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PackStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::PackStmtContext::PACK() {
  return getToken(AslParser::PACK, 0);
}

std::vector<AslParser::ExprContext *> AslParser::PackStmtContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::PackStmtContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::PackStmtContext::INTO() {
  return getToken(AslParser::INTO, 0);
}

AslParser::IdentContext* AslParser::PackStmtContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::PackStmtContext::PackStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::PackStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitPackStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(108);
      left_expr();
      setState(109);
      match(AslParser::ASSIGN);
      setState(110);
      expr(0);
      setState(111);
      match(AslParser::T__8);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(113);
      match(AslParser::IF);
      setState(114);
      expr(0);
      setState(115);
      match(AslParser::THEN);
      setState(116);
      statements();
      setState(119);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(117);
        match(AslParser::ELSE);
        setState(118);
        statements();
      }
      setState(121);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(123);
      match(AslParser::WHILE);
      setState(124);
      expr(0);
      setState(125);
      match(AslParser::DO);
      setState(126);
      statements();
      setState(127);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallNoParamsContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(129);
      ident();
      setState(130);
      match(AslParser::T__0);
      setState(131);
      match(AslParser::T__1);
      setState(132);
      match(AslParser::T__8);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallParamsContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(134);
      ident();
      setState(135);
      match(AslParser::T__0);
      setState(136);
      expr(0);
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__3) {
        setState(137);
        match(AslParser::T__3);
        setState(138);
        expr(0);
        setState(143);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(144);
      match(AslParser::T__1);
      setState(145);
      match(AslParser::T__8);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(147);
      match(AslParser::READ);
      setState(148);
      left_expr();
      setState(149);
      match(AslParser::T__8);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(151);
      match(AslParser::WRITE);
      setState(152);
      expr(0);
      setState(153);
      match(AslParser::T__8);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::PackStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(155);
      match(AslParser::PACK);
      setState(156);
      expr(0);
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__3) {
        setState(157);
        match(AslParser::T__3);
        setState(158);
        expr(0);
        setState(163);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(164);
      match(AslParser::INTO);
      setState(165);
      ident();
      setState(166);
      match(AslParser::T__8);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::UnpackStmtContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(168);
      match(AslParser::UNPACK);
      setState(169);
      ident();
      setState(170);
      match(AslParser::INTO);
      setState(171);
      expr(0);
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__3) {
        setState(172);
        match(AslParser::T__3);
        setState(173);
        expr(0);
        setState(178);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(179);
      match(AslParser::T__8);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(181);
      match(AslParser::WRITE);
      setState(182);
      match(AslParser::STRING);
      setState(183);
      match(AslParser::T__8);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(184);
      match(AslParser::RETURN);
      setState(186);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(185);
        expr(0);
      }
      setState(188);
      match(AslParser::T__8);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::copyFrom(Left_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LeftTupleContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::LeftTupleContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::LeftTupleContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

AslParser::LeftTupleContext::LeftTupleContext(Left_exprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::LeftTupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeftTuple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftArrayContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::LeftArrayContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::LeftArrayContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::LeftArrayContext::LeftArrayContext(Left_exprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::LeftArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeftArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::LeftIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::LeftIdentContext::LeftIdentContext(Left_exprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::LeftIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeftIdent(this);
  else
    return visitor->visitChildren(this);
}
AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::LeftIdentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(191);
      ident();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::LeftArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(192);
      ident();
      setState(193);
      match(AslParser::T__4);
      setState(194);
      expr(0);
      setState(195);
      match(AslParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::LeftTupleContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(197);
      ident();
      setState(198);
      match(AslParser::T__6);
      setState(199);
      match(AslParser::INTVAL);
      setState(200);
      match(AslParser::T__7);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFuncNoParamsContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprFuncNoParamsContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprFuncNoParamsContext::ExprFuncNoParamsContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprFuncNoParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprFuncNoParams(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParsContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParsContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParsContext::ParsContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ParsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitPars(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTupleContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprTupleContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ExprTupleContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

AslParser::ExprTupleContext::ExprTupleContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprTupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprTuple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnitaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnitaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::UnitaryContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

tree::TerminalNode* AslParser::UnitaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

AslParser::UnitaryContext::UnitaryContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::UnitaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnitary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::E() {
  return getToken(AslParser::E, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NE() {
  return getToken(AslParser::NE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GE() {
  return getToken(AslParser::GE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LE() {
  return getToken(AslParser::LE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprArrayContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprArrayContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::ExprArrayContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ExprArrayContext::ExprArrayContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFuncParamsContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprFuncParamsContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ExprFuncParamsContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ExprFuncParamsContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ExprFuncParamsContext::ExprFuncParamsContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprFuncParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprFuncParams(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(205);
      match(AslParser::T__0);
      setState(206);
      expr(0);
      setState(207);
      match(AslParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnitaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      dynamic_cast<UnitaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS))) != 0))) {
        dynamic_cast<UnitaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(210);
      expr(12);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(211);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(212);
      ident();
      setState(213);
      match(AslParser::T__4);
      setState(214);
      expr(0);
      setState(215);
      match(AslParser::T__5);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprTupleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      ident();
      setState(218);
      match(AslParser::T__6);
      setState(219);
      match(AslParser::INTVAL);
      setState(220);
      match(AslParser::T__7);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(222);
      ident();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprFuncNoParamsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      ident();
      setState(224);
      match(AslParser::T__0);
      setState(225);
      match(AslParser::T__1);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprFuncParamsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(227);
      ident();
      setState(228);
      match(AslParser::T__0);
      setState(229);
      expr(0);
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__3) {
        setState(230);
        match(AslParser::T__3);
        setState(231);
        expr(0);
        setState(236);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(237);
      match(AslParser::T__1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(258);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(256);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(241);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(242);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::MUL)
            | (1ULL << AslParser::DIV)
            | (1ULL << AslParser::MOD))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(243);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(244);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(245);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::MINUS)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(246);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(247);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(248);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::E)
            | (1ULL << AslParser::NE)
            | (1ULL << AslParser::GE)
            | (1ULL << AslParser::LE)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::LT))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(249);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(250);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(251);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::AND);
          setState(252);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(253);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(254);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::OR);
          setState(255);
          expr(8);
          break;
        }

        } 
      }
      setState(260);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

antlrcpp::Any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "parameters", "funcType", "declarations", "variable_decl", 
  "type", "basicType", "statements", "statement", "left_expr", "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "')'", "':'", "','", "'['", "']'", "'{'", "'}'", "';'", "'='", 
  "'=='", "'!='", "'>='", "'<='", "'>'", "'<'", "'and'", "'or'", "'not'", 
  "'+'", "'-'", "'*'", "'/'", "'%'", "'var'", "'int'", "'bool'", "'float'", 
  "'char'", "'pack'", "'unpack'", "'into'", "'if'", "'then'", "'else'", 
  "'endif'", "'while'", "'do'", "'endwhile'", "'func'", "'endfunc'", "'return'", 
  "'read'", "'write'", "'array'", "'of'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "ASSIGN", "E", "NE", "GE", "LE", 
  "GT", "LT", "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", "DIV", "MOD", 
  "VAR", "INT", "BOOL", "FLOAT", "CHAR", "PACK", "UNPACK", "INTO", "IF", 
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FUNC", "ENDFUNC", 
  "RETURN", "READ", "WRITE", "ARRAY", "OF", "BOOLVAL", "INTVAL", "FLOATVAL", 
  "CHARVAL", "ID", "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x38, 0x10a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x3, 0x2, 0x6, 0x2, 0x1e, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1f, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x28, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x39, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3c, 
    0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x7, 0x6, 0x42, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x45, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x7, 0x7, 0x4b, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x4e, 0xb, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 
    0x5d, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x60, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x65, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x7, 
    0xa, 0x6a, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6d, 0xb, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x7a, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x8e, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x91, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xa2, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xa5, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb1, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0xb4, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbd, 0xa, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xc0, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0xcd, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xeb, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xee, 0xb, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf2, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x103, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x106, 0xb, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x2, 0x3, 0x18, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x8, 0x3, 0x2, 0x1c, 0x1f, 
    0x3, 0x2, 0x15, 0x17, 0x3, 0x2, 0x31, 0x34, 0x3, 0x2, 0x18, 0x1a, 0x3, 
    0x2, 0x16, 0x17, 0x3, 0x2, 0xd, 0x12, 0x2, 0x124, 0x2, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x23, 0x3, 0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x43, 0x3, 0x2, 0x2, 0x2, 0xc, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x64, 0x3, 0x2, 0x2, 0x2, 0x10, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x14, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xcc, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x107, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 
    0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0x2, 0x2, 0x3, 0x22, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x2a, 0x2, 0x2, 0x24, 0x25, 0x7, 0x35, 
    0x2, 0x2, 0x25, 0x27, 0x7, 0x3, 0x2, 0x2, 0x26, 0x28, 0x5, 0x6, 0x4, 
    0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x2a, 
    0x2c, 0x5, 0x8, 0x5, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x5, 
    0xa, 0x6, 0x2, 0x2e, 0x2f, 0x5, 0x12, 0xa, 0x2, 0x2f, 0x30, 0x7, 0x2b, 
    0x2, 0x2, 0x30, 0x5, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x35, 0x2, 
    0x2, 0x32, 0x33, 0x7, 0x5, 0x2, 0x2, 0x33, 0x3a, 0x5, 0xe, 0x8, 0x2, 
    0x34, 0x35, 0x7, 0x6, 0x2, 0x2, 0x35, 0x36, 0x7, 0x35, 0x2, 0x2, 0x36, 
    0x37, 0x7, 0x5, 0x2, 0x2, 0x37, 0x39, 0x5, 0xe, 0x8, 0x2, 0x38, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x5, 0x2, 
    0x2, 0x3e, 0x3f, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x42, 0x5, 0xc, 0x7, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0xb, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x1b, 0x2, 0x2, 0x47, 0x4c, 0x7, 0x35, 
    0x2, 0x2, 0x48, 0x49, 0x7, 0x6, 0x2, 0x2, 0x49, 0x4b, 0x7, 0x35, 0x2, 
    0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 
    0x7, 0x5, 0x2, 0x2, 0x50, 0x51, 0x5, 0xe, 0x8, 0x2, 0x51, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x2f, 0x2, 0x2, 0x53, 0x54, 0x7, 0x7, 
    0x2, 0x2, 0x54, 0x55, 0x7, 0x32, 0x2, 0x2, 0x55, 0x56, 0x7, 0x8, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0x30, 0x2, 0x2, 0x57, 0x65, 0x5, 0x10, 0x9, 0x2, 
    0x58, 0x59, 0x7, 0x9, 0x2, 0x2, 0x59, 0x5e, 0x5, 0x10, 0x9, 0x2, 0x5a, 
    0x5b, 0x7, 0x6, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0x10, 0x9, 0x2, 0x5c, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0xa, 0x2, 
    0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 0x5, 0x10, 0x9, 0x2, 
    0x64, 0x52, 0x3, 0x2, 0x2, 0x2, 0x64, 0x58, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0xf, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x9, 0x2, 0x2, 0x2, 0x67, 0x11, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x5, 
    0x14, 0xb, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x5, 0x16, 0xc, 0x2, 0x6f, 0x70, 0x7, 0xc, 0x2, 0x2, 0x70, 
    0x71, 0x5, 0x18, 0xd, 0x2, 0x71, 0x72, 0x7, 0xb, 0x2, 0x2, 0x72, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x23, 0x2, 0x2, 0x74, 0x75, 0x5, 
    0x18, 0xd, 0x2, 0x75, 0x76, 0x7, 0x24, 0x2, 0x2, 0x76, 0x79, 0x5, 0x12, 
    0xa, 0x2, 0x77, 0x78, 0x7, 0x25, 0x2, 0x2, 0x78, 0x7a, 0x5, 0x12, 0xa, 
    0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x26, 0x2, 0x2, 0x7c, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x27, 0x2, 0x2, 0x7e, 0x7f, 
    0x5, 0x18, 0xd, 0x2, 0x7f, 0x80, 0x7, 0x28, 0x2, 0x2, 0x80, 0x81, 0x5, 
    0x12, 0xa, 0x2, 0x81, 0x82, 0x7, 0x29, 0x2, 0x2, 0x82, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x5, 0x1a, 0xe, 0x2, 0x84, 0x85, 0x7, 0x3, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0x4, 0x2, 0x2, 0x86, 0x87, 0x7, 0xb, 0x2, 0x2, 
    0x87, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x1a, 0xe, 0x2, 0x89, 
    0x8a, 0x7, 0x3, 0x2, 0x2, 0x8a, 0x8f, 0x5, 0x18, 0xd, 0x2, 0x8b, 0x8c, 
    0x7, 0x6, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x18, 0xd, 0x2, 0x8d, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x4, 0x2, 0x2, 
    0x93, 0x94, 0x7, 0xb, 0x2, 0x2, 0x94, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x96, 0x7, 0x2d, 0x2, 0x2, 0x96, 0x97, 0x5, 0x16, 0xc, 0x2, 0x97, 0x98, 
    0x7, 0xb, 0x2, 0x2, 0x98, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 
    0x2e, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x18, 0xd, 0x2, 0x9b, 0x9c, 0x7, 0xb, 
    0x2, 0x2, 0x9c, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x20, 0x2, 
    0x2, 0x9e, 0xa3, 0x5, 0x18, 0xd, 0x2, 0x9f, 0xa0, 0x7, 0x6, 0x2, 0x2, 
    0xa0, 0xa2, 0x5, 0x18, 0xd, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x22, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x1a, 
    0xe, 0x2, 0xa8, 0xa9, 0x7, 0xb, 0x2, 0x2, 0xa9, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xab, 0x7, 0x21, 0x2, 0x2, 0xab, 0xac, 0x5, 0x1a, 0xe, 0x2, 
    0xac, 0xad, 0x7, 0x22, 0x2, 0x2, 0xad, 0xb2, 0x5, 0x18, 0xd, 0x2, 0xae, 
    0xaf, 0x7, 0x6, 0x2, 0x2, 0xaf, 0xb1, 0x5, 0x18, 0xd, 0x2, 0xb0, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0xb, 0x2, 
    0x2, 0xb6, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x2e, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x36, 0x2, 0x2, 0xb9, 0xc0, 0x7, 0xb, 0x2, 0x2, 0xba, 
    0xbc, 0x7, 0x2c, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x18, 0xd, 0x2, 0xbc, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0xb, 0x2, 0x2, 0xbf, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0x73, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0x83, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0x95, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x99, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xba, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xcd, 0x5, 0x1a, 0xe, 0x2, 0xc2, 0xc3, 0x5, 0x1a, 
    0xe, 0x2, 0xc3, 0xc4, 0x7, 0x7, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x18, 0xd, 
    0x2, 0xc5, 0xc6, 0x7, 0x8, 0x2, 0x2, 0xc6, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x5, 0x1a, 0xe, 0x2, 0xc8, 0xc9, 0x7, 0x9, 0x2, 0x2, 0xc9, 
    0xca, 0x7, 0x32, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xa, 0x2, 0x2, 0xcb, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xcf, 0x8, 0xd, 0x1, 0x2, 0xcf, 0xd0, 0x7, 0x3, 0x2, 
    0x2, 0xd0, 0xd1, 0x5, 0x18, 0xd, 0x2, 0xd1, 0xd2, 0x7, 0x4, 0x2, 0x2, 
    0xd2, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x9, 0x3, 0x2, 0x2, 0xd4, 
    0xf2, 0x5, 0x18, 0xd, 0xe, 0xd5, 0xf2, 0x9, 0x4, 0x2, 0x2, 0xd6, 0xd7, 
    0x5, 0x1a, 0xe, 0x2, 0xd7, 0xd8, 0x7, 0x7, 0x2, 0x2, 0xd8, 0xd9, 0x5, 
    0x18, 0xd, 0x2, 0xd9, 0xda, 0x7, 0x8, 0x2, 0x2, 0xda, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdc, 0x5, 0x1a, 0xe, 0x2, 0xdc, 0xdd, 0x7, 0x9, 0x2, 
    0x2, 0xdd, 0xde, 0x7, 0x32, 0x2, 0x2, 0xde, 0xdf, 0x7, 0xa, 0x2, 0x2, 
    0xdf, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xf2, 0x5, 0x1a, 0xe, 0x2, 0xe1, 
    0xe2, 0x5, 0x1a, 0xe, 0x2, 0xe2, 0xe3, 0x7, 0x3, 0x2, 0x2, 0xe3, 0xe4, 
    0x7, 0x4, 0x2, 0x2, 0xe4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x5, 
    0x1a, 0xe, 0x2, 0xe6, 0xe7, 0x7, 0x3, 0x2, 0x2, 0xe7, 0xec, 0x5, 0x18, 
    0xd, 0x2, 0xe8, 0xe9, 0x7, 0x6, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0x18, 0xd, 
    0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 
    0x7, 0x4, 0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x104, 0x3, 0x2, 0x2, 0x2, 0xf3, 
    0xf4, 0xc, 0xd, 0x2, 0x2, 0xf4, 0xf5, 0x9, 0x5, 0x2, 0x2, 0xf5, 0x103, 
    0x5, 0x18, 0xd, 0xe, 0xf6, 0xf7, 0xc, 0xc, 0x2, 0x2, 0xf7, 0xf8, 0x9, 
    0x6, 0x2, 0x2, 0xf8, 0x103, 0x5, 0x18, 0xd, 0xd, 0xf9, 0xfa, 0xc, 0xb, 
    0x2, 0x2, 0xfa, 0xfb, 0x9, 0x7, 0x2, 0x2, 0xfb, 0x103, 0x5, 0x18, 0xd, 
    0xc, 0xfc, 0xfd, 0xc, 0xa, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x13, 0x2, 0x2, 
    0xfe, 0x103, 0x5, 0x18, 0xd, 0xb, 0xff, 0x100, 0xc, 0x9, 0x2, 0x2, 0x100, 
    0x101, 0x7, 0x14, 0x2, 0x2, 0x101, 0x103, 0x5, 0x18, 0xd, 0xa, 0x102, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0x102, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x102, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x102, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0x35, 
    0x2, 0x2, 0x108, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x1f, 0x27, 0x2b, 0x3a, 
    0x43, 0x4c, 0x5e, 0x64, 0x6b, 0x79, 0x8f, 0xa3, 0xb2, 0xbc, 0xbf, 0xcc, 
    0xec, 0xf1, 0x102, 0x104, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
