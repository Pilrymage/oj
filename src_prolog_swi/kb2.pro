whats_between(N, N, [N]).
whats_between(A, B, R) :- X is A+1, whats_between(X, B, R1), R = [A | R1].
whats_between(N, N, [N]).
whats_between(A, B, [A|R1]) :- X is A+1, whats_between(X, B, R1).

whats_between(A, A, [A]) :- !.
whats_between(A, B, [A|Rest])
  :- Next is A + 1, whats_between(Next, B, Rest).