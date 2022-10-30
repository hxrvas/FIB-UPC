
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, E = 9, NE = 10, GE = 11, LE = 12, GT = 13, LT = 14, AND = 15, 
    OR = 16, NOT = 17, PLUS = 18, MINUS = 19, MUL = 20, DIV = 21, MOD = 22, 
    VAR = 23, INT = 24, BOOL = 25, FLOAT = 26, CHAR = 27, FOR = 28, IN = 29, 
    RANGE = 30, IF = 31, THEN = 32, ELSE = 33, ENDIF = 34, WHILE = 35, DO = 36, 
    ENDWHILE = 37, ENDFOR = 38, FUNC = 39, ENDFUNC = 40, RETURN = 41, READ = 42, 
    WRITE = 43, ARRAY = 44, OF = 45, BOOLVAL = 46, MAX = 47, INTVAL = 48, 
    FLOATVAL = 49, CHARVAL = 50, ID = 51, STRING = 52, COMMENT = 53, WS = 54
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

