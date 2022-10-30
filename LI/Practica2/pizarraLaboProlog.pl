
% Pizarra usada en las primeras dos clases de labo de Prolog, con ejemplos de Prolog

% 
% Una base de datos relacional es un conjunto de "relaciones". 
% Cada relación viene expresada mediante "tuplas".
%   por ejemplo, una relación "estudiante" puede tener las tuplas:
%    estudiante( juan,  21, barcelona, 'Carrer Aragó 453',    ... ). 
%    estudiante( pedro, 22, barcelona, 'Carrer Viladomat 4',  ... ). 
% 
% Si tenemos las relaciones de "padre" y de "hermano":
%  padre(juan,pedro).                  % el padre de juan es pedro
%  padre(maria,pedro).
%  ...                                 % n tuplas en la relación padre

%  hermano(pedro,vicente).             % el hermano de pedro es vicente
%  hermano(pedro,alberto).
%  ...                                 % m tuplas en la relación hermano
% 
% 
% ¿Cómo podríamos hacer la relación "tio"?  Con n x m tuplas?
%        malgastamos espacio (es información que en realidad ya tenemos!!)
%        problemas de consistencia....   restricciones de integridad
%
%  Solución: bases de datos deductivas
%
%  ponemos una regla:
%     forall S,T   tio(S,T) if exists P  such that padre(S,P) AND hermano(P,T)
%
%    diferentes maneras de expresar estas reglas ("cláusulas de Horn de LPO"):
%  
%          A S,T    tio(S,T)  <--    E P  (  padre(S,P)  &   hermano(P,T)  )
%          A S,T    tio(S,T)   v   - E P  (  padre(S,P)  &   hermano(P,T)  )     -E x p(x)   ===   A x  -p(x)
%          A S,T    tio(S,T)   v     A P -(  padre(S,P)  &   hermano(P,T)  )
%          A S,T    tio(S,T)   v     A P  ( -padre(S,P)  v  -hermano(P,T)  )
%          A S,T,P  tio(S,T)   v            -padre(S,P)  v  -hermano(P,T)
%
%                   tio(S,T)   v  -padre(S,P)  v  -hermano(P,T)        % en las cláusulas de LPO no escribimos los As
%  
%  en prolog:       tio(S,T):-     padre(S,P), hermano(P,T).   ("el tio de S es T si el padre de S es P y el hermano de P es T")
%
% programa Prolog === BD deductiva !!


%1 
padre(juan,pedro).      % el padre de juan es pedro
%2 
padre(maria,pedro).
%3 
hermano(pedro,vicente). % el hermano de pedro es vicente
%4 
hermano(pedro,alberto).
%5 
tio(S,T):- padre(S,P), hermano(P,T).          %el ámbito de las variables es la misma cláusula


%?- tio(juan,Z).
% La pila de backtracking:  cuando llama a hermano(pedro,T), usa la 3. y empila la 4.
% da la respuesta Z = vicente
% y si pido más respuestas (con el ;), entonces el backtracking usa lo empilado como alternativa, y usa la 4.


%?- tio(A,B)
% La pila de backtracking:  
%        cuando llama a padre(S,P), usa la 1. y empila la 2.
%        cuando llama a hermano(pedro,T), usa la 3. y empila la 4.
% da la respuesta:
%     A = juan
%     B = vicente
% en este momento la pila contiene  2,4
% y si pido más respuestas (con el ;), entonces el backtracking usa lo último empilado como alternativa, y usa la 4.
% da la respuesta:
%     A = juan
%     B = alberto
% en este momento la pila contiene  2
% y si pido más respuestas (con el ;), entonces el backtracking usa la 2
%        cuando llama a hermano(pedro,T), usa la 3. y empila la 4.
% da la respuesta:
%     A = maria
%     B = vicente
% en este momento la pila contiene  4
% y si pido más respuestas (con el ;), entonces el backtracking usa la 4
% da la respuesta:
%     A = maria
%     B = alberto
% en este momento la pila queda vacía y termina

%




% Lo que hay en una línea detrás del porcentaje % es un comentario.
% En este archivo pizarraLaboProlog.pl  hay muchos comentarios!

% En Prolog, lo que comienza por Mayúscula o por subrayado  _  son variables.
%
% Lo demás son términos;    juan,  hermano(X,juan),  f(X,a),   f(g(a),Z),   ...

% entramos (en linux) en el swi prolog con el comando swipl
% nos da mensaje de bienvenida y saca el prompt:
% ?-
%
% Ahora podemos decirle que lea este archivo, que se llama  pizarraLaboProlog.pl   :
% ?- [pizarraLaboProlog].
% después de esto, ya podemos hacer consultas:
% ?- padre(juan,X).      % esto es nuestro "objetivo"   (inglés: goal)
% ?- padre(Y,pedro).


% ¿Cómo hace el intérprete de Prolog para "ejecutar" un programa Prolog?
% Busca la primera cláusula en la base de datos cuya "cabeza" sea "unificable" con el objetivo:
%  "cabeza".
%  "cabeza" :- "cola".

%  "unificar" = dadas dos expresiones, dar valores a sus variables, para que sean iguales:

%  el simbolo  = significa "es unificable"

% | ?- f(X,a) = f(b,Y).
% | ?- f(f(X),a)  =  f(Y,Y).
% | ?- f(f(X),a) \=  f(Y,Y).
% | ?- f(f(X),a)  =  f(Y,Z).




%"listas"  [ a, b, f(a), g(f(a,X)), [c], X ]
% []                es la lista vacía
% [ a, b | L ]      la | separa los primeros elementos de la LISTA de los demás elementos

% ?- [a,b,c] = [X|L].

% nota: en realidad una lista [a,b,c] es una notación elegante para el término:   .( a, .(b, .(c,[]) ) )




% Prolog es programación DECLARATIVA. NO imperativa
% Esto hace que los programas sean versátiles: la misma definición nos sirve para muchos tipos de consultas.
% Por ejemplo, podemos declarar (definir) qué es pertenecer a una lista: pert(X,L) "X pertenece a la lista L"


% pert(X,L) = "X pertenece a la lista L"      (en realidad ya existe en swi Prolog, y se llama member)
pert(X, [X|_] ).
pert(X, [_|L] ):- pert(X,L).


%concat(L1,L2,L3) = "L3 es la concatenacion de L1 con L2"                     ya existe y se llama append
concat( [],     L,  L       ).
concat( [X|L1], L2, [X|L3] ):- concat( L1, L2, L3).

% aritmetica!!
% Var is Expresion   = "unifica el resultado de evaluar Expresion con Var"

%fact(N,F) = "F es el factorial de N"  F será  N * (N-1) * ... * 1
fact(0,1):- !.
fact(N,F):- N1 is N-1,  fact(N1,F1), F is N * F1.
% en fact(3,F):  para la 3a llamada recursiva con fact(0,...), usa la cláusula 1 y empila la 2!!

%long(L,N) = "la longitud de L es N"                     ya existe y se llama length
long([],0).
long([_|L],N):- long(L,N1), N is N1+1.


%permutacion(L,P) = "P es una permutacion de la lista L"     n!                     ya existe y se llama permutation

permutacion([],[]).
permutacion([X|L], P):- permutacion(L,P1),     
			concat( Pa,    Pb, P1),
			concat( Pa, [X|Pb], P).


%subcjto(L,S) = "S es un subconjunto de L"  2^n
% Si L es [e1 ... en-1 en]
%           0 ...  0    1  
%                       hay tantos subconjuntos como tiras de n bits
subcjto( [], [] ).
subcjto( [_|L],    S  ):-  subcjto(L,S).
subcjto( [X|L], [X|S] ):-  subcjto(L,S).


%cifras( L, N ) escribe las maneras de obtener N a partir de + - * /      de los elementos de la lista L
% ejemplo:
% ?- cifras( [4,9,8,7,100,4], 380 ).
%    4 * (100-7) + 8         <-------------
%    ((100-9) + 4 ) * 4
%    ...

cifras(L,N):-
    subcjto(L,S),         % S = [4,8,7,100]
    permutation(S,P),     % P = [4,100,7,8]
    expresion(P,E),       % E = 4 * (100-7) + 8 
    N is E,
    write(E), nl, fail.


% E = ( 4  *  (100-7) )    +    8
%            +
%          /   \
%         *     8
%        / \
%       4   -
%          / \
%        100  7


expresion([X],X).
expresion( L, E1 +  E2 ):- append( L1, L2, L), 
			  L1 \= [], L2 \= [],
			  expresion( L1, E1 ),
			  expresion( L2, E2 ).
expresion( L, E1 -  E2 ):- append( L1, L2, L), 
			  L1 \= [], L2 \= [],
			  expresion( L1, E1 ),
			  expresion( L2, E2 ).
expresion( L, E1 *  E2 ):- append( L1, L2, L), 
			  L1 \= [], L2 \= [],
			  expresion( L1, E1 ),
			  expresion( L2, E2 ).
expresion( L, E1 // E2 ):- append( L1, L2, L), 
			  L1 \= [], L2 \= [],
			  expresion( L1, E1 ),
			  expresion( L2, E2 ),
                          K is E2, K\=0.              % evitamos que se produzcan divisiones por cero



% Ejemplo para explicar el operador de corte "!":

p(1).                           %1
p(2).                           %2

q(a).                           %3
q(b).                           %4

r(3,4,5).                       %5
r(X,Y,Z):- p(X), q(Y), !, s(Z). %6    el corte ! quita de la pila las alternativas para p(..) q(..) y r(..)
r(5,6,7).                       %7

s(3).                           %8
s(4).                           %9

h(X,Y,Z):- r(X,Y,Z).            %10
% A B C      A B C  

h(a,b,c).                       %11

%% Se comporta así:
%% ?- h(A,B,C), write( [A,B,C] ), nl, fail.
%% [3,4,5]
%% [1,a,3]
%% [1,a,4]
%% [a,b,c]
%% false.



% der( Expr, Var, Der )  == "la derivada de Expr con respecto Var es Der"
der( X, X, 1):- !.
der( C, _, 0):- atomic(C).     % atomic significa que es una expresion constante o un entero
der( A+B, X, U+V ):- der(A,X,U), der(B,X,V). 
der( A*B, X, A*V+B*U ):- der(A,X,U), der(B,X,V). 
% ...


% "not" es "negacion por fallo finito"  "negation by finite failure"
% en realidad el "not" ya está definido en swiprolog, pero si lo tuviéramos que definir, "minot", sería así:

minot( X ):- call(X), !, fail.       %minot( X ):-  X, !, fail.   <--- esto daría error sintáctico; por eso existe el "call"
minot( _ ).




% Haced también los ejercicios de Prolog de los exámenes finales más antiguos (de antes de que existiera el examen de labo).

%% Ejercicios
% 1. Escribe un predicado prod(L,P) que signifique: “P es el producto de los elementos de la lista
% de enteros dada L”. Debe poder generar la P y también comprobar una P dada.
prod([],1).
prod([L|Ls],P):- prod(Ls, P1), P is L * P1.

% 2. Escribe un predicado pescalar(L1,L2,P) que signifique: “P es el producto escalar de los
% vectores L1 y L2”, donde los vectores se representan como listas de enteros. El predicado debe
% fallar si los dos vectores tienen longitudes distintas.
pescalar([],[],0).
pescalar([L1|L1s], [L2|L2s], P):- pescalar(L1s, L2s, P1), P is L1*L2+P1.

% 3. Representando conjuntos con listas sin repeticiones, escribe predicados para las operaciones de
% intersección y unión de conjuntos dados.
myunion([],L,L).
myunion([X|L1],L2,U):- member(X,L2), myunion(L1, L2, U).
myunion([X|L1], L2, [X|U]):- not(member(X,L2)), myunion(L1, L2, U).

myintersection([],_,[]).
myintersection([X|L1],L2,[X|I]):- member(X,L2), myintersection(L1, L2, I).
myintersection([X|L1], L2, I):- not(member(X,L2)), myintersection(L1, L2, I).

% 4. Usando append, escribe un predicado para calcular el último elemento de una lista dada, y otro
% para calcular la lista inversa de una lista dada.
ultimoelem(X, L):- append(_, [X], L). 
%Usando append de esta forma, estamos buscando las dos listas que concatenadas forman L,
%entonces al forzar que la segunda lista sea de un elemento 
%conseguimos el último elemento de L

listainversa([], []).
listainversa([X|L], Reverse):- listainversa(L, ReverseL), append(ReverseL, [X], Reverse).
% 5. Escribe un predicado fib(N,F) que signifique: “F es el N-´esimo n´umero de Fibonacci para la
% N dada”. Estos números se definen así: fib(1) = 1, fib(2) = 1, y si N > 2 entonces fib(N) =
% fib(N − 1) + fib(N − 2).

fib(1,1).
fib(2,1).
fib(N,R) :- N>2, N1 is N-1, N2 is N-2, fib(N1, R1), fib(N2,R2), R is R1+R2.

% 6. Escribe un predicado dados(P,N,L) que signifique: “la lista L expresa una manera de sumar
% P puntos lanzando N dados”. Por ejemplo: si P es 5 y N es 2, una solución sería [1,4] (nótese
% que la longitud de L es N). Tanto P como N vienen instanciados. El predicado debe ser capaz de
% generar todas las soluciones posibles.
dados(0,0,[]).
dados(P,N,[X|L]):- N > 0, member(X, [1,2,3,4,5,6]), N1 is N-1, P1 is P-X, dados(P1,N1,L).

% 7. Escribe un predicado suma_demas(L) que, dada una lista de enteros L, se satisface si existe algún
% elemento en L que es igual a la suma de los demás elementos de L, y falla en caso contrario.
sum([],0).
sum([X|L],P):- sum(L,P1), P is P1+X.

suma_demas(L):- append(L1, [X|L2], L), append(L1, L2, Rest), sum(Rest, X).

% 8. Escribe un predicado suma_ants(L) que, dada una lista de enteros L, se satisface si existe algún
% elemento en L que es igual a la suma de los elementos anteriores a él en L, y falla en caso
% contrario.
suma_ants(L):- append(L1, [X|_], L), sum(L1, X).

% 9. Escribe un predicado card(L) que, dada una lista de enteros L, escriba la lista que, para cada
% elemento de L, dice cuántas veces aparece este elemento en L. Por ejemplo, si hacemos la consulta
% card( [1,2,1,5,1,3,3,7] ) el intérprete escribirá:
% [[1,3],[2,1],[5,1],[3,2],[7,1]].

card(L):- findall([I, N], (member(I, L), findall(I, member(I,L), Repes), length(Repes, N)), List), setof(M, member(M,List), Result), write(Result).

% 10. Escribe un predicado esta ordenada(L) que signifique: “la lista L de números enteros está
% ordenada de menor a mayor”. Por ejemplo, a la consulta:
% ?-esta ordenada([3,45,67,83]).
% el intérprete responde yes, y a la consulta:
% ?-esta ordenada([3,67,45]).
% responde no.

esta_ordenada([]). % La lista vacia esta ordenada
esta_ordenada([_]). % Una lista de un solo elemento esta ordenada
esta_ordenada([X,Y|L]):- X < Y, esta_ordenada([Y|L]).

% 11. Escribe un predicado ord(L1,L2) que signifique: “L2 es la lista de enteros L1 ordenada de
% menor a mayor”. Por ejemplo: si L1 es [4,5,3,3,2] entonces L2 será [2,3,3,4,5]. Hazlo en
% una línea, usando sólo los predicados permutacion y esta_ordenada.
ord(L1,L2):- permutacion(L1,L2), esta_ordenada(L2).

% 12. Escribe un predicado diccionario(A,N) que, dado un alfabeto A de símbolos y un natural N,
% escriba todas las palabras de N símbolos, por orden alfabético (el orden alfabético es según el
% alfabeto A dado). Por ejemplo, diccionario( [ga,chu,le],2) escribirá:
% gaga gachu gale chuga chuchu chule lega lechu lele.

palabra([], _, 0).
palabra([C|W], A, N):- N > 0, N1 is N-1, member(C, A), palabra(W, A, N1).
diccionario(A,N):- palabra(W, A, N), atomic_list_concat(W,L), write(L), write(" "), fail.
diccionario(_,_).
% 13. Escribe un predicado palindromos(L) que, dada una lista de letras L, escriba todas las permutaciones de sus elementos que sean palíndromos (capicúas). Por ejemplo, con la consulta
% palindromos([a,a,c,c]) se escribe [a,c,c,a] y [c,a,a,c].
equal_list([], []).   
equal_list([H1|R1], [H2|R2]):- H1 = H2, equal_list(R1, R2).

even(N):- mod(N,2) =:= 0.

palindromo(L):- listainversa(L,L).

palindromos(L):- setof(Lp, (permutacion(L, Lp), palindromo(Lp)),Result), write(Result).
% 14. Encuentra mediante un programa Prolog, usando el predicado permutación, qué 8 dígitos diferentes tenemos que asignar a las letras S, E, N, D, M, O, R, Y, de manera que se cumpla la suma
% siguiente:
% S E N D
% + M O R E
% M O N E Y

moneyProblem:- Letters = [S,E,N,D,M,O,R,Y,_,_], Numbers = [0,1,2,3,4,5,6,7,8,9], permutation(Letters, Numbers), 
	S1 is 1000 * S + 100 * E + 10 * N + D + 1000 * M + 100 * O + 10 * R + E,
	S2 is 10000 * M + 1000 * O + 100 * N + 10 * E + Y,
	S1=:=S2,
	writeLetters(Letters), ! .

                                
writeLetters([S, E, N, D, M, O, R, Y, _, _]):-
	write('S = '), write(S), nl,
	write('E = '), write(E), nl,
	write('N = '), write(N), nl,
	write('D = '), write(D), nl,
	write('M = '), write(M), nl,
	write('O = '), write(O), nl,                                                 
	write('R = '), write(R), nl,
	write('Y = '), write(Y), nl.


% 15. Escribe un predicado simplifica que pueda usarse en combinación con el programa de calcular
% derivadas.

simplifica(E,E1):- unpaso(E,E2),!, simplifica(E2,E1).
simplifica(E,E).

unpaso(A+B,A+C):- unpaso(B,C),!.
unpaso(B+A,C+A):- unpaso(B,C),!.
unpaso(A*B,A*C):- unpaso(B,C),!.
unpaso(B*A,C*A):- unpaso(B,C),!.
unpaso(0*_,0):-!.
unpaso(_*0,0):-!.
unpaso(1*X,X):-!.
unpaso(X*1,X):-!.
unpaso(0+X,X):-!.
unpaso(X+0,X):-!.
unpaso(N1+N2,N3):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(N1*N2,N3):- number(N1), number(N2), N3 is N1*N2,!.
unpaso(N1*X+N2*X,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(N1*X+X*N2,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(X*N1+N2*X,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(X*N1+X*N2,N3*X):- number(N1), number(N2), N3 is N1+N2,!.

% 16. Queremos obtener en Prolog un predicado dom(L) que, dada una lista L de fichas de dominó (en
% el formato de abajo), escriba una cadena de dominó usando todas las fichas de L, o escriba “no
% hay cadena” si no es posible. Por ejemplo,
% ?- dom( [ f(3,4), f(2,3), f(1,6), f(2,2), f(4,2), f(2,1) ] ).
% escribe la cadena correcta:
% [ f(2,3), f(3,4), f(4,2), f(2,2), f(2,1), f(1,6) ].
% También podemos girar alguna ficha como f(N,M), reemplazándola por f(M,N). Así, para:
% ?- dom([ f(4,3), f(2,3), f(1,6), f(2,2), f(2,4), f(2,1) ]).
% sólo hay cadena si se gira alguna ficha (por ejemplo, hay la misma cadena que antes).
% El siguiente programa Prolog aún no tiene en cuenta los posibles giros de fichas, ni tiene implementado el predicado ok(P), que significa: “P es una cadena de dominó correcta (tal cual, sin
% necesidad ya de girar ninguna ficha)”:
% (a) ¿Qué significa el predicado p(L,P) para una lista L dada?
	% P es una permutación de las fichas de L
% (b) Escribe el predicado ok(P) que falta.
% (c) Extiende el predicado p para que el programa también pueda hacer cadenas girando alguna
% de las fichas de la entrada.
ok([]).
ok([_]).
ok([f(_,X), f(Y, Z) | P]):- X == Y, ok([ f(Y, Z) | P]).
p([],[]).
p(L,[f(X,Y)|P]):- (select(f(X,Y),L,R); select(f(Y,X), L, R)), p(R,P).
dom(L):- p(L,P), ok(P), write(P), nl.
dom(_):- write("No hay cadena"), nl.


% 17. Complete the following backtracking procedure for SAT in Prolog. Program everything, except
% the predicate readclauses(F), which reads a list of clauses, where each clause is a list of integers.
% For example, p3 ∨ ¬p6 ∨ p2 is represented by [3,-6,2]. Do things as simple as possible.
%p:- readclauses(F), sat([],F).
%p:- write(’UNSAT’),nl.
%sat(I,[]):- write(’IT IS SATISFIABLE. Model: ’), write(I),nl,!.
%sat(I,F):-
%	decision lit(F,Lit), % Select unit clause if any; otherwise, an arbitrary one.
%	simplif(Lit,F,F1), % Simplifies F. Warning: may fail and cause backtracking
%	sat( ... , ... ).


% 18. Consider two groups of 10 people each. In the first group, as expected, the percentage of people
% with lung cancer among smokers is higher than among non-smokers. In the second group, the
% same is the case. But if we consider the 20 people of the two groups together, then the situation
% is the opposite: the proportion of people with lung cancer is higher among non-smokers than
% among smokers! Can this be true? Write a little Prolog program to find it out.

%%No esta bien creo
smoker(I):- I == 1.
nonsmoker(I):- I == 0.

tengroup(L):- length(L, 10), findall(I, (smoker(I), member(I, L)), Smokers), findall(J, (nonsmoker(J), member(J, L)), Nonsmokers),
				length(Smokers, N1), length(Nonsmokers, N2), N1 > N2.

twentygroup([L1|L2]):- tengroup(L1), tengroup(L2), append(L1,L2,L), findall(I, (smoker(I), member(I, L)), Smokers), findall(J, (nonsmoker(J), member(J, L)), Nonsmokers),
length(Smokers, N1), length(Nonsmokers, N2), N1 < N2.


% 19. Supongamos que tenemos una máquina que dispone de monedas de valores [X1,...Xn] y tiene
% que devolver una cantidad C de cambio utilizando el mínimo número de monedas. Escribe un
% programa Prolog maq(L,C,M) que, dada la lista de monedas L y la cantidad C, genere en M la
% lista de monedas a devolver de cada tipo. Por ejemplo, si L es [1,2,5,13,17,35,157], y C es
% 361, entonces una respuesta es [0,0,0,1,2,0,2] (5 monedas).
% Note: greedy algorithms (starting with the largest coin, etc.) do not always work!

% 20. Write in Prolog a predicate flatten(L,F) that “flattens” (cast.: “aplana”) the list F as in the
% example:
% ?-flatten( [a,b,[c,[d],e,[]],f,[g,h]], F ).
% F=[a,b,c,d,e,f,g,h]?
flatten([], []):- !.
flatten(X, [X]):- X\=[_|_].
flatten([L|List], FList):- flatten(L, L2), flatten(List, List2), append(L2, List2, FList).

% 21. Escribe un predicado Prolog log(B,N,L) que calcula la parte entera L del logaritmo en base B
% de N, donde B y N son naturales positivos dados. Por ejemplo, ?- log(2,1020,L). escribe L=9?
% Podéis usar la exponenciación, como en 125 is 5**3. El programa (completo) no debe ocupar
% más de 3 lineas.

log(B,N,L):- between(1, N, L), E is B**L, NB is N//B, E > NB, N >= E.

% 22. Supongamos que N estudiantes (identificados por un número entre 1 y N) se quieren matricular
% de LI, pero sólo hay espacio para M, con M < N. Además nos dan una lista L de pares de estos
% estudiantes que son incompatibles entre sí (por ejemplo, porque siempre se copian). Queremos
% obtener un programa Prolog li(N,M,L,S) que, para N, M y L dados, genere un subconjunto S
% con M de los N estudiantes tal que si [x, y] ∈ L entonces {x, y} 6⊆ S. Por ejemplo, una solución de
% li( 20, 16, [[8,11],[8,15],[11,6],[4,9],[18,13],[7,9],[16,8],[18,10],[6,17],[8,20]], S )
% es [20,19,17,16,15,14,13,12,11,10,7,5,4,3,2,1] .
% Escribe una versión lo más sencilla que puedas, aunque sea ineficiente, del estilo “generar una
% solución (total) y después comprobar si es correcta”.

comprueba([],_).
comprueba([[A,B]|L], S):- (not(member(A, S)); not(member(B, S))), comprueba(L, S).
li(N, M, L, S):- findall(E, between(1, N, E), Estudiantes), subcjto(Estudiantes, S), length(S, M), comprueba(L, S).