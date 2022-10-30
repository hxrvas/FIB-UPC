
// Generated from Calc.g4 by ANTLR 4.7.2


#include "CalcVisitor.h"

#include "CalcParser.h"


using namespace antlrcpp;
using namespace antlr4;

CalcParser::CalcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CalcParser::~CalcParser() {
  delete _interpreter;
}

std::string CalcParser::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CalcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

CalcParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ProgContext::EOF() {
  return getToken(CalcParser::EOF, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::ProgContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::ProgContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}


size_t CalcParser::ProgContext::getRuleIndex() const {
  return CalcParser::RuleProg;
}

antlrcpp::Any CalcParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ProgContext* CalcParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(8);
      stat();
      setState(11); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CalcParser::T__1)
      | (1ULL << CalcParser::MAX)
      | (1ULL << CalcParser::SUB)
      | (1ULL << CalcParser::ID)
      | (1ULL << CalcParser::INT)
      | (1ULL << CalcParser::NEWLINE))) != 0));
    setState(13);
    match(CalcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CalcParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}

void CalcParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::BlankContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::PrintExprContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::PrintExprContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AssignContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::ExprContext* CalcParser::AssignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AssignContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
CalcParser::StatContext* CalcParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(15);
      expr(0);
      setState(16);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::AssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(18);
      match(CalcParser::ID);
      setState(19);
      match(CalcParser::T__0);
      setState(20);
      expr(0);
      setState(21);
      match(CalcParser::NEWLINE);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::BlankContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(23);
      match(CalcParser::NEWLINE);
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

CalcParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}

void CalcParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NegContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::NegContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::ExprContext* CalcParser::NegContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

CalcParser::NegContext::NegContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::NegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitNeg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::CompContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::CompContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::CompContext::GT() {
  return getToken(CalcParser::GT, 0);
}

tree::TerminalNode* CalcParser::CompContext::LT() {
  return getToken(CalcParser::LT, 0);
}

tree::TerminalNode* CalcParser::CompContext::EQ() {
  return getToken(CalcParser::EQ, 0);
}

CalcParser::CompContext::CompContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::CompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitComp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::PlusMinusContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::PlusMinusContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::PlusMinusContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::PlusMinusContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::PlusMinusContext::PlusMinusContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProdContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::ProdContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ProdContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ProdContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

CalcParser::ProdContext::ProdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::ProdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MaxContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::MaxContext::MAX() {
  return getToken(CalcParser::MAX, 0);
}

CalcParser::ExprListContext* CalcParser::MaxContext::exprList() {
  return getRuleContext<CalcParser::ExprListContext>(0);
}

CalcParser::MaxContext::MaxContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::MaxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMax(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParsContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::ParsContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

CalcParser::ParsContext::ParsContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::ParsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPars(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivisContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::DivisContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::DivisContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::DivisContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

CalcParser::DivisContext::DivisContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::DivisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitDivis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactoContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::FactoContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::FactoContext::FACT() {
  return getToken(CalcParser::FACT, 0);
}

CalcParser::FactoContext::FactoContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::FactoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitFacto(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IdContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IntContext::INT() {
  return getToken(CalcParser::INT, 0);
}

CalcParser::IntContext::IntContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ExprContext* CalcParser::expr() {
   return expr(0);
}

CalcParser::ExprContext* CalcParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalcParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::SUB: {
        _localctx = _tracker.createInstance<NegContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(27);
        match(CalcParser::SUB);
        setState(28);
        expr(7);
        break;
      }

      case CalcParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(29);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(30);
        match(CalcParser::ID);
        break;
      }

      case CalcParser::T__1: {
        _localctx = _tracker.createInstance<ParsContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(31);
        match(CalcParser::T__1);
        setState(32);
        expr(0);
        setState(33);
        match(CalcParser::T__2);
        break;
      }

      case CalcParser::MAX: {
        _localctx = _tracker.createInstance<MaxContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(35);
        match(CalcParser::MAX);
        setState(36);
        match(CalcParser::T__1);
        setState(37);
        exprList();
        setState(38);
        match(CalcParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(58);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(56);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ProdContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(42);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(43);
          match(CalcParser::MUL);
          setState(44);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivisContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(45);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(46);
          match(CalcParser::DIV);
          setState(47);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<PlusMinusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(48);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(49);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(50);
          expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(51);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(52);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CalcParser::GT)
            | (1ULL << CalcParser::LT)
            | (1ULL << CalcParser::EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(53);
          expr(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<FactoContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(54);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(55);
          match(CalcParser::FACT);
          break;
        }

        } 
      }
      setState(60);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

CalcParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CalcParser::ExprContext *> CalcParser::ExprListContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ExprListContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}


size_t CalcParser::ExprListContext::getRuleIndex() const {
  return CalcParser::RuleExprList;
}

antlrcpp::Any CalcParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ExprListContext* CalcParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 6, CalcParser::RuleExprList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    expr(0);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CalcParser::T__3) {
      setState(62);
      match(CalcParser::T__3);
      setState(63);
      expr(0);
      setState(68);
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

bool CalcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CalcParser::_decisionToDFA;
atn::PredictionContextCache CalcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CalcParser::_atn;
std::vector<uint16_t> CalcParser::_serializedATN;

std::vector<std::string> CalcParser::_ruleNames = {
  "prog", "stat", "expr", "exprList"
};

std::vector<std::string> CalcParser::_literalNames = {
  "", "'='", "'('", "')'", "','", "'max'", "'*'", "'/'", "'+'", "'-'", "'!'", 
  "'>'", "'<'"
};

std::vector<std::string> CalcParser::_symbolicNames = {
  "", "", "", "", "", "MAX", "MUL", "DIV", "ADD", "SUB", "FACT", "GT", "LT", 
  "EQ", "ID", "INT", "NEWLINE", "WS"
};

dfa::Vocabulary CalcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CalcParser::_tokenNames;

CalcParser::Initializer::Initializer() {
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
    0x3, 0x13, 0x48, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x6, 0x2, 0xc, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0xd, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1b, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x2b, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3b, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x3e, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x5, 0x2, 0x3, 0x6, 
    0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x4, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0xd, 
    0xf, 0x2, 0x50, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1a, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xc, 0x5, 0x4, 0x3, 0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 
    0x2, 0xe, 0xf, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x7, 0x2, 0x2, 0x3, 0x10, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x5, 0x6, 0x4, 0x2, 0x12, 0x13, 
    0x7, 0x12, 0x2, 0x2, 0x13, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 
    0x10, 0x2, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 0x16, 0x17, 0x5, 0x6, 
    0x4, 0x2, 0x17, 0x18, 0x7, 0x12, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1b, 0x7, 0x12, 0x2, 0x2, 0x1a, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x14, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x8, 0x4, 0x1, 0x2, 0x1d, 0x1e, 
    0x7, 0xb, 0x2, 0x2, 0x1e, 0x2b, 0x5, 0x6, 0x4, 0x9, 0x1f, 0x2b, 0x7, 
    0x11, 0x2, 0x2, 0x20, 0x2b, 0x7, 0x10, 0x2, 0x2, 0x21, 0x22, 0x7, 0x4, 
    0x2, 0x2, 0x22, 0x23, 0x5, 0x6, 0x4, 0x2, 0x23, 0x24, 0x7, 0x5, 0x2, 
    0x2, 0x24, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x7, 0x2, 0x2, 
    0x26, 0x27, 0x7, 0x4, 0x2, 0x2, 0x27, 0x28, 0x5, 0x8, 0x5, 0x2, 0x28, 
    0x29, 0x7, 0x5, 0x2, 0x2, 0x29, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x2a, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0xc, 0xc, 0x2, 
    0x2, 0x2d, 0x2e, 0x7, 0x8, 0x2, 0x2, 0x2e, 0x3b, 0x5, 0x6, 0x4, 0xd, 
    0x2f, 0x30, 0xc, 0xb, 0x2, 0x2, 0x30, 0x31, 0x7, 0x9, 0x2, 0x2, 0x31, 
    0x3b, 0x5, 0x6, 0x4, 0xc, 0x32, 0x33, 0xc, 0xa, 0x2, 0x2, 0x33, 0x34, 
    0x9, 0x2, 0x2, 0x2, 0x34, 0x3b, 0x5, 0x6, 0x4, 0xb, 0x35, 0x36, 0xc, 
    0x7, 0x2, 0x2, 0x36, 0x37, 0x9, 0x3, 0x2, 0x2, 0x37, 0x3b, 0x5, 0x6, 
    0x4, 0x8, 0x38, 0x39, 0xc, 0x8, 0x2, 0x2, 0x39, 0x3b, 0x7, 0xc, 0x2, 
    0x2, 0x3a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x32, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x35, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x44, 0x5, 0x6, 
    0x4, 0x2, 0x40, 0x41, 0x7, 0x6, 0x2, 0x2, 0x41, 0x43, 0x5, 0x6, 0x4, 
    0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 0xd, 0x1a, 
    0x2a, 0x3a, 0x3c, 0x44, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CalcParser::Initializer CalcParser::_init;
