
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, ASSIGN = 9, E = 10, NE = 11, GE = 12, LE = 13, GT = 14, LT = 15, 
    AND = 16, OR = 17, NOT = 18, PLUS = 19, MINUS = 20, MUL = 21, DIV = 22, 
    MOD = 23, VAR = 24, INT = 25, BOOL = 26, FLOAT = 27, CHAR = 28, IF = 29, 
    THEN = 30, ELSE = 31, ENDIF = 32, WHILE = 33, DO = 34, ENDWHILE = 35, 
    PAIR = 36, ENDPAIR = 37, FUNC = 38, ENDFUNC = 39, RETURN = 40, READ = 41, 
    WRITE = 42, ARRAY = 43, OF = 44, FIRST = 45, SECOND = 46, BOOLVAL = 47, 
    INTVAL = 48, FLOATVAL = 49, CHARVAL = 50, ID = 51, STRING = 52, COMMENT = 53, 
    WS = 54
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

