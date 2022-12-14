// Generated from /home/joan/Escritorio/CL/practica/examen2018/asl/Asl.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, ASSIGN=9, 
		E=10, NE=11, GE=12, LE=13, GT=14, LT=15, AND=16, OR=17, NOT=18, PLUS=19, 
		MINUS=20, MUL=21, DIV=22, MOD=23, VAR=24, INT=25, BOOL=26, FLOAT=27, CHAR=28, 
		IF=29, THEN=30, ELSE=31, ENDIF=32, WHILE=33, DO=34, ENDWHILE=35, PAIR=36, 
		ENDPAIR=37, FUNC=38, ENDFUNC=39, RETURN=40, READ=41, WRITE=42, ARRAY=43, 
		OF=44, FIRST=45, SECOND=46, BOOLVAL=47, INTVAL=48, FLOATVAL=49, CHARVAL=50, 
		ID=51, STRING=52, COMMENT=53, WS=54;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "ASSIGN", 
			"E", "NE", "GE", "LE", "GT", "LT", "AND", "OR", "NOT", "PLUS", "MINUS", 
			"MUL", "DIV", "MOD", "VAR", "INT", "BOOL", "FLOAT", "CHAR", "IF", "THEN", 
			"ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "PAIR", "ENDPAIR", "FUNC", 
			"ENDFUNC", "RETURN", "READ", "WRITE", "ARRAY", "OF", "FIRST", "SECOND", 
			"BOOLVAL", "INTVAL", "FLOATVAL", "CHARVAL", "ID", "STRING", "ESC_SEQ", 
			"COMMENT", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "':'", "','", "'['", "']'", "';'", "'.'", "'='", 
			"'=='", "'!='", "'>='", "'<='", "'>'", "'<'", "'and'", "'or'", "'not'", 
			"'+'", "'-'", "'*'", "'/'", "'%'", "'var'", "'int'", "'bool'", "'float'", 
			"'char'", "'if'", "'then'", "'else'", "'endif'", "'while'", "'do'", "'endwhile'", 
			"'pair'", "'endpair'", "'func'", "'endfunc'", "'return'", "'read'", "'write'", 
			"'array'", "'of'", "'first'", "'second'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "ASSIGN", "E", 
			"NE", "GE", "LE", "GT", "LT", "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", 
			"DIV", "MOD", "VAR", "INT", "BOOL", "FLOAT", "CHAR", "IF", "THEN", "ELSE", 
			"ENDIF", "WHILE", "DO", "ENDWHILE", "PAIR", "ENDPAIR", "FUNC", "ENDFUNC", 
			"RETURN", "READ", "WRITE", "ARRAY", "OF", "FIRST", "SECOND", "BOOLVAL", 
			"INTVAL", "FLOATVAL", "CHARVAL", "ID", "STRING", "COMMENT", "WS"
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


	public AslLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\28\u0175\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3"+
		"\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3\f"+
		"\3\r\3\r\3\r\3\16\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\21\3\21\3"+
		"\22\3\22\3\22\3\23\3\23\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3"+
		"\27\3\30\3\30\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\33\3\33\3\33\3"+
		"\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\36\3"+
		"\36\3\36\3\37\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\""+
		"\3\"\3\"\3\"\3\"\3\"\3#\3#\3#\3$\3$\3$\3$\3$\3$\3$\3$\3$\3%\3%\3%\3%\3"+
		"%\3&\3&\3&\3&\3&\3&\3&\3&\3\'\3\'\3\'\3\'\3\'\3(\3(\3(\3(\3(\3(\3(\3("+
		"\3)\3)\3)\3)\3)\3)\3)\3*\3*\3*\3*\3*\3+\3+\3+\3+\3+\3+\3,\3,\3,\3,\3,"+
		"\3,\3-\3-\3-\3.\3.\3.\3.\3.\3.\3/\3/\3/\3/\3/\3/\3/\3\60\3\60\3\60\3\60"+
		"\3\60\3\60\3\60\3\60\3\60\5\60\u0131\n\60\3\61\6\61\u0134\n\61\r\61\16"+
		"\61\u0135\3\62\6\62\u0139\n\62\r\62\16\62\u013a\3\62\3\62\7\62\u013f\n"+
		"\62\f\62\16\62\u0142\13\62\3\63\3\63\3\63\5\63\u0147\n\63\3\63\3\63\3"+
		"\64\3\64\7\64\u014d\n\64\f\64\16\64\u0150\13\64\3\65\3\65\3\65\7\65\u0155"+
		"\n\65\f\65\16\65\u0158\13\65\3\65\3\65\3\66\3\66\3\66\3\67\3\67\3\67\3"+
		"\67\7\67\u0163\n\67\f\67\16\67\u0166\13\67\3\67\5\67\u0169\n\67\3\67\3"+
		"\67\3\67\3\67\38\68\u0170\n8\r8\168\u0171\38\38\2\29\3\3\5\4\7\5\t\6\13"+
		"\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'"+
		"\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'"+
		"M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63e\64g\65i\66k\2m\67o8\3\2\t\4\2))^^\4"+
		"\2C\\c|\6\2\62;C\\aac|\4\2$$^^\n\2$$))^^ddhhppttvv\4\2\f\f\17\17\5\2\13"+
		"\f\17\17\"\"\2\u017e\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2"+
		"\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3"+
		"\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2"+
		"\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2"+
		"\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2"+
		"\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2"+
		"\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q"+
		"\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2"+
		"\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2"+
		"\2m\3\2\2\2\2o\3\2\2\2\3q\3\2\2\2\5s\3\2\2\2\7u\3\2\2\2\tw\3\2\2\2\13"+
		"y\3\2\2\2\r{\3\2\2\2\17}\3\2\2\2\21\177\3\2\2\2\23\u0081\3\2\2\2\25\u0083"+
		"\3\2\2\2\27\u0086\3\2\2\2\31\u0089\3\2\2\2\33\u008c\3\2\2\2\35\u008f\3"+
		"\2\2\2\37\u0091\3\2\2\2!\u0093\3\2\2\2#\u0097\3\2\2\2%\u009a\3\2\2\2\'"+
		"\u009e\3\2\2\2)\u00a0\3\2\2\2+\u00a2\3\2\2\2-\u00a4\3\2\2\2/\u00a6\3\2"+
		"\2\2\61\u00a8\3\2\2\2\63\u00ac\3\2\2\2\65\u00b0\3\2\2\2\67\u00b5\3\2\2"+
		"\29\u00bb\3\2\2\2;\u00c0\3\2\2\2=\u00c3\3\2\2\2?\u00c8\3\2\2\2A\u00cd"+
		"\3\2\2\2C\u00d3\3\2\2\2E\u00d9\3\2\2\2G\u00dc\3\2\2\2I\u00e5\3\2\2\2K"+
		"\u00ea\3\2\2\2M\u00f2\3\2\2\2O\u00f7\3\2\2\2Q\u00ff\3\2\2\2S\u0106\3\2"+
		"\2\2U\u010b\3\2\2\2W\u0111\3\2\2\2Y\u0117\3\2\2\2[\u011a\3\2\2\2]\u0120"+
		"\3\2\2\2_\u0130\3\2\2\2a\u0133\3\2\2\2c\u0138\3\2\2\2e\u0143\3\2\2\2g"+
		"\u014a\3\2\2\2i\u0151\3\2\2\2k\u015b\3\2\2\2m\u015e\3\2\2\2o\u016f\3\2"+
		"\2\2qr\7*\2\2r\4\3\2\2\2st\7+\2\2t\6\3\2\2\2uv\7<\2\2v\b\3\2\2\2wx\7."+
		"\2\2x\n\3\2\2\2yz\7]\2\2z\f\3\2\2\2{|\7_\2\2|\16\3\2\2\2}~\7=\2\2~\20"+
		"\3\2\2\2\177\u0080\7\60\2\2\u0080\22\3\2\2\2\u0081\u0082\7?\2\2\u0082"+
		"\24\3\2\2\2\u0083\u0084\7?\2\2\u0084\u0085\7?\2\2\u0085\26\3\2\2\2\u0086"+
		"\u0087\7#\2\2\u0087\u0088\7?\2\2\u0088\30\3\2\2\2\u0089\u008a\7@\2\2\u008a"+
		"\u008b\7?\2\2\u008b\32\3\2\2\2\u008c\u008d\7>\2\2\u008d\u008e\7?\2\2\u008e"+
		"\34\3\2\2\2\u008f\u0090\7@\2\2\u0090\36\3\2\2\2\u0091\u0092\7>\2\2\u0092"+
		" \3\2\2\2\u0093\u0094\7c\2\2\u0094\u0095\7p\2\2\u0095\u0096\7f\2\2\u0096"+
		"\"\3\2\2\2\u0097\u0098\7q\2\2\u0098\u0099\7t\2\2\u0099$\3\2\2\2\u009a"+
		"\u009b\7p\2\2\u009b\u009c\7q\2\2\u009c\u009d\7v\2\2\u009d&\3\2\2\2\u009e"+
		"\u009f\7-\2\2\u009f(\3\2\2\2\u00a0\u00a1\7/\2\2\u00a1*\3\2\2\2\u00a2\u00a3"+
		"\7,\2\2\u00a3,\3\2\2\2\u00a4\u00a5\7\61\2\2\u00a5.\3\2\2\2\u00a6\u00a7"+
		"\7\'\2\2\u00a7\60\3\2\2\2\u00a8\u00a9\7x\2\2\u00a9\u00aa\7c\2\2\u00aa"+
		"\u00ab\7t\2\2\u00ab\62\3\2\2\2\u00ac\u00ad\7k\2\2\u00ad\u00ae\7p\2\2\u00ae"+
		"\u00af\7v\2\2\u00af\64\3\2\2\2\u00b0\u00b1\7d\2\2\u00b1\u00b2\7q\2\2\u00b2"+
		"\u00b3\7q\2\2\u00b3\u00b4\7n\2\2\u00b4\66\3\2\2\2\u00b5\u00b6\7h\2\2\u00b6"+
		"\u00b7\7n\2\2\u00b7\u00b8\7q\2\2\u00b8\u00b9\7c\2\2\u00b9\u00ba\7v\2\2"+
		"\u00ba8\3\2\2\2\u00bb\u00bc\7e\2\2\u00bc\u00bd\7j\2\2\u00bd\u00be\7c\2"+
		"\2\u00be\u00bf\7t\2\2\u00bf:\3\2\2\2\u00c0\u00c1\7k\2\2\u00c1\u00c2\7"+
		"h\2\2\u00c2<\3\2\2\2\u00c3\u00c4\7v\2\2\u00c4\u00c5\7j\2\2\u00c5\u00c6"+
		"\7g\2\2\u00c6\u00c7\7p\2\2\u00c7>\3\2\2\2\u00c8\u00c9\7g\2\2\u00c9\u00ca"+
		"\7n\2\2\u00ca\u00cb\7u\2\2\u00cb\u00cc\7g\2\2\u00cc@\3\2\2\2\u00cd\u00ce"+
		"\7g\2\2\u00ce\u00cf\7p\2\2\u00cf\u00d0\7f\2\2\u00d0\u00d1\7k\2\2\u00d1"+
		"\u00d2\7h\2\2\u00d2B\3\2\2\2\u00d3\u00d4\7y\2\2\u00d4\u00d5\7j\2\2\u00d5"+
		"\u00d6\7k\2\2\u00d6\u00d7\7n\2\2\u00d7\u00d8\7g\2\2\u00d8D\3\2\2\2\u00d9"+
		"\u00da\7f\2\2\u00da\u00db\7q\2\2\u00dbF\3\2\2\2\u00dc\u00dd\7g\2\2\u00dd"+
		"\u00de\7p\2\2\u00de\u00df\7f\2\2\u00df\u00e0\7y\2\2\u00e0\u00e1\7j\2\2"+
		"\u00e1\u00e2\7k\2\2\u00e2\u00e3\7n\2\2\u00e3\u00e4\7g\2\2\u00e4H\3\2\2"+
		"\2\u00e5\u00e6\7r\2\2\u00e6\u00e7\7c\2\2\u00e7\u00e8\7k\2\2\u00e8\u00e9"+
		"\7t\2\2\u00e9J\3\2\2\2\u00ea\u00eb\7g\2\2\u00eb\u00ec\7p\2\2\u00ec\u00ed"+
		"\7f\2\2\u00ed\u00ee\7r\2\2\u00ee\u00ef\7c\2\2\u00ef\u00f0\7k\2\2\u00f0"+
		"\u00f1\7t\2\2\u00f1L\3\2\2\2\u00f2\u00f3\7h\2\2\u00f3\u00f4\7w\2\2\u00f4"+
		"\u00f5\7p\2\2\u00f5\u00f6\7e\2\2\u00f6N\3\2\2\2\u00f7\u00f8\7g\2\2\u00f8"+
		"\u00f9\7p\2\2\u00f9\u00fa\7f\2\2\u00fa\u00fb\7h\2\2\u00fb\u00fc\7w\2\2"+
		"\u00fc\u00fd\7p\2\2\u00fd\u00fe\7e\2\2\u00feP\3\2\2\2\u00ff\u0100\7t\2"+
		"\2\u0100\u0101\7g\2\2\u0101\u0102\7v\2\2\u0102\u0103\7w\2\2\u0103\u0104"+
		"\7t\2\2\u0104\u0105\7p\2\2\u0105R\3\2\2\2\u0106\u0107\7t\2\2\u0107\u0108"+
		"\7g\2\2\u0108\u0109\7c\2\2\u0109\u010a\7f\2\2\u010aT\3\2\2\2\u010b\u010c"+
		"\7y\2\2\u010c\u010d\7t\2\2\u010d\u010e\7k\2\2\u010e\u010f\7v\2\2\u010f"+
		"\u0110\7g\2\2\u0110V\3\2\2\2\u0111\u0112\7c\2\2\u0112\u0113\7t\2\2\u0113"+
		"\u0114\7t\2\2\u0114\u0115\7c\2\2\u0115\u0116\7{\2\2\u0116X\3\2\2\2\u0117"+
		"\u0118\7q\2\2\u0118\u0119\7h\2\2\u0119Z\3\2\2\2\u011a\u011b\7h\2\2\u011b"+
		"\u011c\7k\2\2\u011c\u011d\7t\2\2\u011d\u011e\7u\2\2\u011e\u011f\7v\2\2"+
		"\u011f\\\3\2\2\2\u0120\u0121\7u\2\2\u0121\u0122\7g\2\2\u0122\u0123\7e"+
		"\2\2\u0123\u0124\7q\2\2\u0124\u0125\7p\2\2\u0125\u0126\7f\2\2\u0126^\3"+
		"\2\2\2\u0127\u0128\7v\2\2\u0128\u0129\7t\2\2\u0129\u012a\7w\2\2\u012a"+
		"\u0131\7g\2\2\u012b\u012c\7h\2\2\u012c\u012d\7c\2\2\u012d\u012e\7n\2\2"+
		"\u012e\u012f\7u\2\2\u012f\u0131\7g\2\2\u0130\u0127\3\2\2\2\u0130\u012b"+
		"\3\2\2\2\u0131`\3\2\2\2\u0132\u0134\4\62;\2\u0133\u0132\3\2\2\2\u0134"+
		"\u0135\3\2\2\2\u0135\u0133\3\2\2\2\u0135\u0136\3\2\2\2\u0136b\3\2\2\2"+
		"\u0137\u0139\4\62;\2\u0138\u0137\3\2\2\2\u0139\u013a\3\2\2\2\u013a\u0138"+
		"\3\2\2\2\u013a\u013b\3\2\2\2\u013b\u013c\3\2\2\2\u013c\u0140\7\60\2\2"+
		"\u013d\u013f\4\62;\2\u013e\u013d\3\2\2\2\u013f\u0142\3\2\2\2\u0140\u013e"+
		"\3\2\2\2\u0140\u0141\3\2\2\2\u0141d\3\2\2\2\u0142\u0140\3\2\2\2\u0143"+
		"\u0146\7)\2\2\u0144\u0147\n\2\2\2\u0145\u0147\5k\66\2\u0146\u0144\3\2"+
		"\2\2\u0146\u0145\3\2\2\2\u0147\u0148\3\2\2\2\u0148\u0149\7)\2\2\u0149"+
		"f\3\2\2\2\u014a\u014e\t\3\2\2\u014b\u014d\t\4\2\2\u014c\u014b\3\2\2\2"+
		"\u014d\u0150\3\2\2\2\u014e\u014c\3\2\2\2\u014e\u014f\3\2\2\2\u014fh\3"+
		"\2\2\2\u0150\u014e\3\2\2\2\u0151\u0156\7$\2\2\u0152\u0155\5k\66\2\u0153"+
		"\u0155\n\5\2\2\u0154\u0152\3\2\2\2\u0154\u0153\3\2\2\2\u0155\u0158\3\2"+
		"\2\2\u0156\u0154\3\2\2\2\u0156\u0157\3\2\2\2\u0157\u0159\3\2\2\2\u0158"+
		"\u0156\3\2\2\2\u0159\u015a\7$\2\2\u015aj\3\2\2\2\u015b\u015c\7^\2\2\u015c"+
		"\u015d\t\6\2\2\u015dl\3\2\2\2\u015e\u015f\7\61\2\2\u015f\u0160\7\61\2"+
		"\2\u0160\u0164\3\2\2\2\u0161\u0163\n\7\2\2\u0162\u0161\3\2\2\2\u0163\u0166"+
		"\3\2\2\2\u0164\u0162\3\2\2\2\u0164\u0165\3\2\2\2\u0165\u0168\3\2\2\2\u0166"+
		"\u0164\3\2\2\2\u0167\u0169\7\17\2\2\u0168\u0167\3\2\2\2\u0168\u0169\3"+
		"\2\2\2\u0169\u016a\3\2\2\2\u016a\u016b\7\f\2\2\u016b\u016c\3\2\2\2\u016c"+
		"\u016d\b\67\2\2\u016dn\3\2\2\2\u016e\u0170\t\b\2\2\u016f\u016e\3\2\2\2"+
		"\u0170\u0171\3\2\2\2\u0171\u016f\3\2\2\2\u0171\u0172\3\2\2\2\u0172\u0173"+
		"\3\2\2\2\u0173\u0174\b8\2\2\u0174p\3\2\2\2\16\2\u0130\u0135\u013a\u0140"+
		"\u0146\u014e\u0154\u0156\u0164\u0168\u0171\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}