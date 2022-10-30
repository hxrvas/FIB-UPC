// Generated from /home/joan/Escritorio/CL/practica/examen2021/asl/Asl.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, ASSIGN=8, E=9, 
		NE=10, GE=11, LE=12, GT=13, LT=14, AND=15, OR=16, NOT=17, PLUS=18, MINUS=19, 
		MUL=20, DIV=21, MOD=22, VAR=23, INT=24, BOOL=25, FLOAT=26, CHAR=27, IF=28, 
		THEN=29, ELSE=30, ENDIF=31, WHILE=32, DO=33, ENDWHILE=34, FUNC=35, ENDFUNC=36, 
		RETURN=37, READ=38, WRITE=39, ARRAY=40, OF=41, MAP=42, INTO=43, USING=44, 
		POT=45, BOOLVAL=46, INTVAL=47, FLOATVAL=48, CHARVAL=49, ID=50, STRING=51, 
		COMMENT=52, WS=53;
	public static final int
		RULE_program = 0, RULE_function = 1, RULE_parameters = 2, RULE_funcType = 3, 
		RULE_declarations = 4, RULE_variable_decl = 5, RULE_type = 6, RULE_basicType = 7, 
		RULE_statements = 8, RULE_statement = 9, RULE_left_expr = 10, RULE_expr = 11, 
		RULE_ident = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "function", "parameters", "funcType", "declarations", "variable_decl", 
			"type", "basicType", "statements", "statement", "left_expr", "expr", 
			"ident"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "':'", "','", "'['", "']'", "';'", "'='", "'=='", 
			"'!='", "'>='", "'<='", "'>'", "'<'", "'and'", "'or'", "'not'", "'+'", 
			"'-'", "'*'", "'/'", "'%'", "'var'", "'int'", "'bool'", "'float'", "'char'", 
			"'if'", "'then'", "'else'", "'endif'", "'while'", "'do'", "'endwhile'", 
			"'func'", "'endfunc'", "'return'", "'read'", "'write'", "'array'", "'of'", 
			"'map'", "'into'", "'using'", "'**'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "ASSIGN", "E", "NE", 
			"GE", "LE", "GT", "LT", "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", "DIV", 
			"MOD", "VAR", "INT", "BOOL", "FLOAT", "CHAR", "IF", "THEN", "ELSE", "ENDIF", 
			"WHILE", "DO", "ENDWHILE", "FUNC", "ENDFUNC", "RETURN", "READ", "WRITE", 
			"ARRAY", "OF", "MAP", "INTO", "USING", "POT", "BOOLVAL", "INTVAL", "FLOATVAL", 
			"CHARVAL", "ID", "STRING", "COMMENT", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AslParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AslParser.EOF, 0); }
		public List<FunctionContext> function() {
			return getRuleContexts(FunctionContext.class);
		}
		public FunctionContext function(int i) {
			return getRuleContext(FunctionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(27); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(26);
				function();
				}
				}
				setState(29); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==FUNC );
			setState(31);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode FUNC() { return getToken(AslParser.FUNC, 0); }
		public TerminalNode ID() { return getToken(AslParser.ID, 0); }
		public DeclarationsContext declarations() {
			return getRuleContext(DeclarationsContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode ENDFUNC() { return getToken(AslParser.ENDFUNC, 0); }
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public FuncTypeContext funcType() {
			return getRuleContext(FuncTypeContext.class,0);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(33);
			match(FUNC);
			setState(34);
			match(ID);
			setState(35);
			match(T__0);
			setState(37);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ID) {
				{
				setState(36);
				parameters();
				}
			}

			setState(39);
			match(T__1);
			setState(41);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__2) {
				{
				setState(40);
				funcType();
				}
			}

			setState(43);
			declarations();
			setState(44);
			statements();
			setState(45);
			match(ENDFUNC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParametersContext extends ParserRuleContext {
		public List<TerminalNode> ID() { return getTokens(AslParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(AslParser.ID, i);
		}
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_parameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			match(ID);
			setState(48);
			match(T__2);
			setState(49);
			type();
			setState(56);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(50);
				match(T__3);
				setState(51);
				match(ID);
				setState(52);
				match(T__2);
				setState(53);
				type();
				}
				}
				setState(58);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncTypeContext extends ParserRuleContext {
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public FuncTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcType; }
	}

	public final FuncTypeContext funcType() throws RecognitionException {
		FuncTypeContext _localctx = new FuncTypeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_funcType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			match(T__2);
			setState(60);
			basicType();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationsContext extends ParserRuleContext {
		public List<Variable_declContext> variable_decl() {
			return getRuleContexts(Variable_declContext.class);
		}
		public Variable_declContext variable_decl(int i) {
			return getRuleContext(Variable_declContext.class,i);
		}
		public DeclarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarations; }
	}

	public final DeclarationsContext declarations() throws RecognitionException {
		DeclarationsContext _localctx = new DeclarationsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_declarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(65);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==VAR) {
				{
				{
				setState(62);
				variable_decl();
				}
				}
				setState(67);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variable_declContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(AslParser.VAR, 0); }
		public List<TerminalNode> ID() { return getTokens(AslParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(AslParser.ID, i);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public Variable_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_decl; }
	}

	public final Variable_declContext variable_decl() throws RecognitionException {
		Variable_declContext _localctx = new Variable_declContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_variable_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(VAR);
			setState(69);
			match(ID);
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__3) {
				{
				{
				setState(70);
				match(T__3);
				setState(71);
				match(ID);
				}
				}
				setState(76);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(77);
			match(T__2);
			setState(78);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	 
		public TypeContext() { }
		public void copyFrom(TypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArrayDeclContext extends TypeContext {
		public TerminalNode ARRAY() { return getToken(AslParser.ARRAY, 0); }
		public TerminalNode INTVAL() { return getToken(AslParser.INTVAL, 0); }
		public TerminalNode OF() { return getToken(AslParser.OF, 0); }
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public ArrayDeclContext(TypeContext ctx) { copyFrom(ctx); }
	}
	public static class BasicContext extends TypeContext {
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public BasicContext(TypeContext ctx) { copyFrom(ctx); }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_type);
		try {
			setState(87);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ARRAY:
				_localctx = new ArrayDeclContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				match(ARRAY);
				setState(81);
				match(T__4);
				setState(82);
				match(INTVAL);
				setState(83);
				match(T__5);
				setState(84);
				match(OF);
				setState(85);
				basicType();
				}
				break;
			case INT:
			case BOOL:
			case FLOAT:
			case CHAR:
				_localctx = new BasicContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(86);
				basicType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BasicTypeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(AslParser.INT, 0); }
		public TerminalNode BOOL() { return getToken(AslParser.BOOL, 0); }
		public TerminalNode FLOAT() { return getToken(AslParser.FLOAT, 0); }
		public TerminalNode CHAR() { return getToken(AslParser.CHAR, 0); }
		public BasicTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basicType; }
	}

	public final BasicTypeContext basicType() throws RecognitionException {
		BasicTypeContext _localctx = new BasicTypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_basicType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << BOOL) | (1L << FLOAT) | (1L << CHAR))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementsContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(94);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << WHILE) | (1L << RETURN) | (1L << READ) | (1L << WRITE) | (1L << MAP) | (1L << ID))) != 0)) {
				{
				{
				setState(91);
				statement();
				}
				}
				setState(96);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class WriteExprContext extends StatementContext {
		public TerminalNode WRITE() { return getToken(AslParser.WRITE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public WriteExprContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class WhileStmtContext extends StatementContext {
		public TerminalNode WHILE() { return getToken(AslParser.WHILE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode DO() { return getToken(AslParser.DO, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode ENDWHILE() { return getToken(AslParser.ENDWHILE, 0); }
		public WhileStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class IfStmtContext extends StatementContext {
		public TerminalNode IF() { return getToken(AslParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode THEN() { return getToken(AslParser.THEN, 0); }
		public List<StatementsContext> statements() {
			return getRuleContexts(StatementsContext.class);
		}
		public StatementsContext statements(int i) {
			return getRuleContext(StatementsContext.class,i);
		}
		public TerminalNode ENDIF() { return getToken(AslParser.ENDIF, 0); }
		public TerminalNode ELSE() { return getToken(AslParser.ELSE, 0); }
		public IfStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ReadStmtContext extends StatementContext {
		public TerminalNode READ() { return getToken(AslParser.READ, 0); }
		public Left_exprContext left_expr() {
			return getRuleContext(Left_exprContext.class,0);
		}
		public ReadStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ProcCallParamsContext extends StatementContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ProcCallParamsContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ProcCallNoParamsContext extends StatementContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ProcCallNoParamsContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class AssignStmtContext extends StatementContext {
		public Left_exprContext left_expr() {
			return getRuleContext(Left_exprContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AslParser.ASSIGN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class MapStmtContext extends StatementContext {
		public TerminalNode MAP() { return getToken(AslParser.MAP, 0); }
		public List<IdentContext> ident() {
			return getRuleContexts(IdentContext.class);
		}
		public IdentContext ident(int i) {
			return getRuleContext(IdentContext.class,i);
		}
		public TerminalNode INTO() { return getToken(AslParser.INTO, 0); }
		public TerminalNode USING() { return getToken(AslParser.USING, 0); }
		public MapStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ReturnStmtContext extends StatementContext {
		public TerminalNode RETURN() { return getToken(AslParser.RETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ReturnStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class WriteStringContext extends StatementContext {
		public TerminalNode WRITE() { return getToken(AslParser.WRITE, 0); }
		public TerminalNode STRING() { return getToken(AslParser.STRING, 0); }
		public WriteStringContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_statement);
		int _la;
		try {
			setState(160);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				_localctx = new AssignStmtContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(97);
				left_expr();
				setState(98);
				match(ASSIGN);
				setState(99);
				expr(0);
				setState(100);
				match(T__6);
				}
				break;
			case 2:
				_localctx = new MapStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(102);
				match(MAP);
				setState(103);
				ident();
				setState(104);
				match(INTO);
				setState(105);
				ident();
				setState(106);
				match(USING);
				setState(107);
				ident();
				setState(108);
				match(T__6);
				}
				break;
			case 3:
				_localctx = new IfStmtContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(110);
				match(IF);
				setState(111);
				expr(0);
				setState(112);
				match(THEN);
				setState(113);
				statements();
				setState(116);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ELSE) {
					{
					setState(114);
					match(ELSE);
					setState(115);
					statements();
					}
				}

				setState(118);
				match(ENDIF);
				}
				break;
			case 4:
				_localctx = new WhileStmtContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(120);
				match(WHILE);
				setState(121);
				expr(0);
				setState(122);
				match(DO);
				setState(123);
				statements();
				setState(124);
				match(ENDWHILE);
				}
				break;
			case 5:
				_localctx = new ProcCallNoParamsContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(126);
				ident();
				setState(127);
				match(T__0);
				setState(128);
				match(T__1);
				setState(129);
				match(T__6);
				}
				break;
			case 6:
				_localctx = new ProcCallParamsContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(131);
				ident();
				setState(132);
				match(T__0);
				setState(133);
				expr(0);
				setState(138);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(134);
					match(T__3);
					setState(135);
					expr(0);
					}
					}
					setState(140);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(141);
				match(T__1);
				setState(142);
				match(T__6);
				}
				break;
			case 7:
				_localctx = new ReadStmtContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(144);
				match(READ);
				setState(145);
				left_expr();
				setState(146);
				match(T__6);
				}
				break;
			case 8:
				_localctx = new WriteExprContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(148);
				match(WRITE);
				setState(149);
				expr(0);
				setState(150);
				match(T__6);
				}
				break;
			case 9:
				_localctx = new WriteStringContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(152);
				match(WRITE);
				setState(153);
				match(STRING);
				setState(154);
				match(T__6);
				}
				break;
			case 10:
				_localctx = new ReturnStmtContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(155);
				match(RETURN);
				setState(157);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << NOT) | (1L << PLUS) | (1L << MINUS) | (1L << BOOLVAL) | (1L << INTVAL) | (1L << FLOATVAL) | (1L << CHARVAL) | (1L << ID))) != 0)) {
					{
					setState(156);
					expr(0);
					}
				}

				setState(159);
				match(T__6);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Left_exprContext extends ParserRuleContext {
		public Left_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_left_expr; }
	 
		public Left_exprContext() { }
		public void copyFrom(Left_exprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class LeftArrayContext extends Left_exprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public LeftArrayContext(Left_exprContext ctx) { copyFrom(ctx); }
	}
	public static class LeftIdentContext extends Left_exprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public LeftIdentContext(Left_exprContext ctx) { copyFrom(ctx); }
	}

	public final Left_exprContext left_expr() throws RecognitionException {
		Left_exprContext _localctx = new Left_exprContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_left_expr);
		try {
			setState(168);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				_localctx = new LeftIdentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				ident();
				}
				break;
			case 2:
				_localctx = new LeftArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(163);
				ident();
				setState(164);
				match(T__4);
				setState(165);
				expr(0);
				setState(166);
				match(T__5);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class PotenciaContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode POT() { return getToken(AslParser.POT, 0); }
		public PotenciaContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class BooleanContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode AND() { return getToken(AslParser.AND, 0); }
		public TerminalNode OR() { return getToken(AslParser.OR, 0); }
		public BooleanContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprFuncNoParamsContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ExprFuncNoParamsContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ParsContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParsContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class UnitaryContext extends ExprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(AslParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(AslParser.MINUS, 0); }
		public TerminalNode NOT() { return getToken(AslParser.NOT, 0); }
		public UnitaryContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprIdentContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ExprIdentContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ArithmeticContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(AslParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(AslParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(AslParser.MOD, 0); }
		public TerminalNode PLUS() { return getToken(AslParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(AslParser.MINUS, 0); }
		public ArithmeticContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class RelationalContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode E() { return getToken(AslParser.E, 0); }
		public TerminalNode NE() { return getToken(AslParser.NE, 0); }
		public TerminalNode GE() { return getToken(AslParser.GE, 0); }
		public TerminalNode LE() { return getToken(AslParser.LE, 0); }
		public TerminalNode GT() { return getToken(AslParser.GT, 0); }
		public TerminalNode LT() { return getToken(AslParser.LT, 0); }
		public RelationalContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprArrayContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprArrayContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ValueContext extends ExprContext {
		public TerminalNode INTVAL() { return getToken(AslParser.INTVAL, 0); }
		public TerminalNode FLOATVAL() { return getToken(AslParser.FLOATVAL, 0); }
		public TerminalNode BOOLVAL() { return getToken(AslParser.BOOLVAL, 0); }
		public TerminalNode CHARVAL() { return getToken(AslParser.CHARVAL, 0); }
		public ValueContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprFuncParamsContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprFuncParamsContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				_localctx = new ParsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(171);
				match(T__0);
				setState(172);
				expr(0);
				setState(173);
				match(T__1);
				}
				break;
			case 2:
				{
				_localctx = new ExprArrayContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(175);
				ident();
				setState(176);
				match(T__4);
				setState(177);
				expr(0);
				setState(178);
				match(T__5);
				}
				break;
			case 3:
				{
				_localctx = new ExprFuncNoParamsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(180);
				ident();
				setState(181);
				match(T__0);
				setState(182);
				match(T__1);
				}
				break;
			case 4:
				{
				_localctx = new ExprFuncParamsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(184);
				ident();
				setState(185);
				match(T__0);
				setState(186);
				expr(0);
				setState(191);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__3) {
					{
					{
					setState(187);
					match(T__3);
					setState(188);
					expr(0);
					}
					}
					setState(193);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(194);
				match(T__1);
				}
				break;
			case 5:
				{
				_localctx = new UnitaryContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(196);
				((UnitaryContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NOT) | (1L << PLUS) | (1L << MINUS))) != 0)) ) {
					((UnitaryContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(197);
				expr(8);
				}
				break;
			case 6:
				{
				_localctx = new ExprIdentContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(198);
				ident();
				}
				break;
			case 7:
				{
				_localctx = new ValueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(199);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLVAL) | (1L << INTVAL) | (1L << FLOATVAL) | (1L << CHARVAL))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(222);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(220);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						_localctx = new PotenciaContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(202);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(203);
						((PotenciaContext)_localctx).op = match(POT);
						setState(204);
						expr(10);
						}
						break;
					case 2:
						{
						_localctx = new ArithmeticContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(205);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(206);
						((ArithmeticContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MUL) | (1L << DIV) | (1L << MOD))) != 0)) ) {
							((ArithmeticContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(207);
						expr(8);
						}
						break;
					case 3:
						{
						_localctx = new ArithmeticContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(208);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(209);
						((ArithmeticContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((ArithmeticContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(210);
						expr(7);
						}
						break;
					case 4:
						{
						_localctx = new RelationalContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(211);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(212);
						((RelationalContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << E) | (1L << NE) | (1L << GE) | (1L << LE) | (1L << GT) | (1L << LT))) != 0)) ) {
							((RelationalContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(213);
						expr(6);
						}
						break;
					case 5:
						{
						_localctx = new BooleanContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(214);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(215);
						((BooleanContext)_localctx).op = match(AND);
						setState(216);
						expr(5);
						}
						break;
					case 6:
						{
						_localctx = new BooleanContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(217);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(218);
						((BooleanContext)_localctx).op = match(OR);
						setState(219);
						expr(4);
						}
						break;
					}
					} 
				}
				setState(224);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class IdentContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(AslParser.ID, 0); }
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_ident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 11:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 9);
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		case 4:
			return precpred(_ctx, 4);
		case 5:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\67\u00e6\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\6\2\36\n\2\r\2\16\2\37\3\2\3\2\3\3"+
		"\3\3\3\3\3\3\5\3(\n\3\3\3\3\3\5\3,\n\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\7\49\n\4\f\4\16\4<\13\4\3\5\3\5\3\5\3\6\7\6B\n\6\f\6\16\6"+
		"E\13\6\3\7\3\7\3\7\3\7\7\7K\n\7\f\7\16\7N\13\7\3\7\3\7\3\7\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\5\bZ\n\b\3\t\3\t\3\n\7\n_\n\n\f\n\16\nb\13\n\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\5\13w\n\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\7\13\u008b\n\13\f\13\16"+
		"\13\u008e\13\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\5\13\u00a0\n\13\3\13\5\13\u00a3\n\13\3\f\3\f"+
		"\3\f\3\f\3\f\3\f\5\f\u00ab\n\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r"+
		"\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u00c0\n\r\f\r\16\r\u00c3\13\r"+
		"\3\r\3\r\3\r\3\r\3\r\3\r\5\r\u00cb\n\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r"+
		"\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u00df\n\r\f\r\16\r\u00e2"+
		"\13\r\3\16\3\16\3\16\2\3\30\17\2\4\6\b\n\f\16\20\22\24\26\30\32\2\b\3"+
		"\2\32\35\3\2\23\25\3\2\60\63\3\2\26\30\3\2\24\25\3\2\13\20\2\u00fa\2\35"+
		"\3\2\2\2\4#\3\2\2\2\6\61\3\2\2\2\b=\3\2\2\2\nC\3\2\2\2\fF\3\2\2\2\16Y"+
		"\3\2\2\2\20[\3\2\2\2\22`\3\2\2\2\24\u00a2\3\2\2\2\26\u00aa\3\2\2\2\30"+
		"\u00ca\3\2\2\2\32\u00e3\3\2\2\2\34\36\5\4\3\2\35\34\3\2\2\2\36\37\3\2"+
		"\2\2\37\35\3\2\2\2\37 \3\2\2\2 !\3\2\2\2!\"\7\2\2\3\"\3\3\2\2\2#$\7%\2"+
		"\2$%\7\64\2\2%\'\7\3\2\2&(\5\6\4\2\'&\3\2\2\2\'(\3\2\2\2()\3\2\2\2)+\7"+
		"\4\2\2*,\5\b\5\2+*\3\2\2\2+,\3\2\2\2,-\3\2\2\2-.\5\n\6\2./\5\22\n\2/\60"+
		"\7&\2\2\60\5\3\2\2\2\61\62\7\64\2\2\62\63\7\5\2\2\63:\5\16\b\2\64\65\7"+
		"\6\2\2\65\66\7\64\2\2\66\67\7\5\2\2\679\5\16\b\28\64\3\2\2\29<\3\2\2\2"+
		":8\3\2\2\2:;\3\2\2\2;\7\3\2\2\2<:\3\2\2\2=>\7\5\2\2>?\5\20\t\2?\t\3\2"+
		"\2\2@B\5\f\7\2A@\3\2\2\2BE\3\2\2\2CA\3\2\2\2CD\3\2\2\2D\13\3\2\2\2EC\3"+
		"\2\2\2FG\7\31\2\2GL\7\64\2\2HI\7\6\2\2IK\7\64\2\2JH\3\2\2\2KN\3\2\2\2"+
		"LJ\3\2\2\2LM\3\2\2\2MO\3\2\2\2NL\3\2\2\2OP\7\5\2\2PQ\5\16\b\2Q\r\3\2\2"+
		"\2RS\7*\2\2ST\7\7\2\2TU\7\61\2\2UV\7\b\2\2VW\7+\2\2WZ\5\20\t\2XZ\5\20"+
		"\t\2YR\3\2\2\2YX\3\2\2\2Z\17\3\2\2\2[\\\t\2\2\2\\\21\3\2\2\2]_\5\24\13"+
		"\2^]\3\2\2\2_b\3\2\2\2`^\3\2\2\2`a\3\2\2\2a\23\3\2\2\2b`\3\2\2\2cd\5\26"+
		"\f\2de\7\n\2\2ef\5\30\r\2fg\7\t\2\2g\u00a3\3\2\2\2hi\7,\2\2ij\5\32\16"+
		"\2jk\7-\2\2kl\5\32\16\2lm\7.\2\2mn\5\32\16\2no\7\t\2\2o\u00a3\3\2\2\2"+
		"pq\7\36\2\2qr\5\30\r\2rs\7\37\2\2sv\5\22\n\2tu\7 \2\2uw\5\22\n\2vt\3\2"+
		"\2\2vw\3\2\2\2wx\3\2\2\2xy\7!\2\2y\u00a3\3\2\2\2z{\7\"\2\2{|\5\30\r\2"+
		"|}\7#\2\2}~\5\22\n\2~\177\7$\2\2\177\u00a3\3\2\2\2\u0080\u0081\5\32\16"+
		"\2\u0081\u0082\7\3\2\2\u0082\u0083\7\4\2\2\u0083\u0084\7\t\2\2\u0084\u00a3"+
		"\3\2\2\2\u0085\u0086\5\32\16\2\u0086\u0087\7\3\2\2\u0087\u008c\5\30\r"+
		"\2\u0088\u0089\7\6\2\2\u0089\u008b\5\30\r\2\u008a\u0088\3\2\2\2\u008b"+
		"\u008e\3\2\2\2\u008c\u008a\3\2\2\2\u008c\u008d\3\2\2\2\u008d\u008f\3\2"+
		"\2\2\u008e\u008c\3\2\2\2\u008f\u0090\7\4\2\2\u0090\u0091\7\t\2\2\u0091"+
		"\u00a3\3\2\2\2\u0092\u0093\7(\2\2\u0093\u0094\5\26\f\2\u0094\u0095\7\t"+
		"\2\2\u0095\u00a3\3\2\2\2\u0096\u0097\7)\2\2\u0097\u0098\5\30\r\2\u0098"+
		"\u0099\7\t\2\2\u0099\u00a3\3\2\2\2\u009a\u009b\7)\2\2\u009b\u009c\7\65"+
		"\2\2\u009c\u00a3\7\t\2\2\u009d\u009f\7\'\2\2\u009e\u00a0\5\30\r\2\u009f"+
		"\u009e\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0\u00a1\3\2\2\2\u00a1\u00a3\7\t"+
		"\2\2\u00a2c\3\2\2\2\u00a2h\3\2\2\2\u00a2p\3\2\2\2\u00a2z\3\2\2\2\u00a2"+
		"\u0080\3\2\2\2\u00a2\u0085\3\2\2\2\u00a2\u0092\3\2\2\2\u00a2\u0096\3\2"+
		"\2\2\u00a2\u009a\3\2\2\2\u00a2\u009d\3\2\2\2\u00a3\25\3\2\2\2\u00a4\u00ab"+
		"\5\32\16\2\u00a5\u00a6\5\32\16\2\u00a6\u00a7\7\7\2\2\u00a7\u00a8\5\30"+
		"\r\2\u00a8\u00a9\7\b\2\2\u00a9\u00ab\3\2\2\2\u00aa\u00a4\3\2\2\2\u00aa"+
		"\u00a5\3\2\2\2\u00ab\27\3\2\2\2\u00ac\u00ad\b\r\1\2\u00ad\u00ae\7\3\2"+
		"\2\u00ae\u00af\5\30\r\2\u00af\u00b0\7\4\2\2\u00b0\u00cb\3\2\2\2\u00b1"+
		"\u00b2\5\32\16\2\u00b2\u00b3\7\7\2\2\u00b3\u00b4\5\30\r\2\u00b4\u00b5"+
		"\7\b\2\2\u00b5\u00cb\3\2\2\2\u00b6\u00b7\5\32\16\2\u00b7\u00b8\7\3\2\2"+
		"\u00b8\u00b9\7\4\2\2\u00b9\u00cb\3\2\2\2\u00ba\u00bb\5\32\16\2\u00bb\u00bc"+
		"\7\3\2\2\u00bc\u00c1\5\30\r\2\u00bd\u00be\7\6\2\2\u00be\u00c0\5\30\r\2"+
		"\u00bf\u00bd\3\2\2\2\u00c0\u00c3\3\2\2\2\u00c1\u00bf\3\2\2\2\u00c1\u00c2"+
		"\3\2\2\2\u00c2\u00c4\3\2\2\2\u00c3\u00c1\3\2\2\2\u00c4\u00c5\7\4\2\2\u00c5"+
		"\u00cb\3\2\2\2\u00c6\u00c7\t\3\2\2\u00c7\u00cb\5\30\r\n\u00c8\u00cb\5"+
		"\32\16\2\u00c9\u00cb\t\4\2\2\u00ca\u00ac\3\2\2\2\u00ca\u00b1\3\2\2\2\u00ca"+
		"\u00b6\3\2\2\2\u00ca\u00ba\3\2\2\2\u00ca\u00c6\3\2\2\2\u00ca\u00c8\3\2"+
		"\2\2\u00ca\u00c9\3\2\2\2\u00cb\u00e0\3\2\2\2\u00cc\u00cd\f\13\2\2\u00cd"+
		"\u00ce\7/\2\2\u00ce\u00df\5\30\r\f\u00cf\u00d0\f\t\2\2\u00d0\u00d1\t\5"+
		"\2\2\u00d1\u00df\5\30\r\n\u00d2\u00d3\f\b\2\2\u00d3\u00d4\t\6\2\2\u00d4"+
		"\u00df\5\30\r\t\u00d5\u00d6\f\7\2\2\u00d6\u00d7\t\7\2\2\u00d7\u00df\5"+
		"\30\r\b\u00d8\u00d9\f\6\2\2\u00d9\u00da\7\21\2\2\u00da\u00df\5\30\r\7"+
		"\u00db\u00dc\f\5\2\2\u00dc\u00dd\7\22\2\2\u00dd\u00df\5\30\r\6\u00de\u00cc"+
		"\3\2\2\2\u00de\u00cf\3\2\2\2\u00de\u00d2\3\2\2\2\u00de\u00d5\3\2\2\2\u00de"+
		"\u00d8\3\2\2\2\u00de\u00db\3\2\2\2\u00df\u00e2\3\2\2\2\u00e0\u00de\3\2"+
		"\2\2\u00e0\u00e1\3\2\2\2\u00e1\31\3\2\2\2\u00e2\u00e0\3\2\2\2\u00e3\u00e4"+
		"\7\64\2\2\u00e4\33\3\2\2\2\23\37\'+:CLY`v\u008c\u009f\u00a2\u00aa\u00c1"+
		"\u00ca\u00de\u00e0";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}