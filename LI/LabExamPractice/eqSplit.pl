%% Write a Prolog predicate eqSplit(L,S1,S2) that, given a list of
%% integers L, splits it into two disjoint subsets S1 and S2 such that
%% the sum of the numbers in S1 is equal to the sum of S2. It should
%% behave as follows:
%%
%% ?- eqSplit([1,5,2,3,4,7],S1,S2), write(S1), write('    '), write(S2), nl, fail.
%%
%% [1,5,2,3]    [4,7]
%% [1,3,7]    [5,2,4]
%% [5,2,4]    [1,3,7]
%% [4,7]    [1,5,2,3]
subcjto( [], [] ).
subcjto( [_|L],    S  ):-  subcjto(L,S).
subcjto( [X|L], [X|S] ):-  subcjto(L,S).
sum([],0).
sum([X|L],P):- sum(L,P1), P is P1+X.

eqSplit(L,S1,S2):- subcjto(L, S1), subcjto(L,S2), length(L, A), append(S1, S2, S), length(S, A), intersection(S1, S2, I), length(I,0), sum(S1, N), sum(S2, M), N==M.
