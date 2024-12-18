% Facts
father(john, jim).
father(john, ann).
mother(lisa, jim).
mother(lisa, ann).
male(john).
female(lisa).

% Rules
parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Queries
% Is John the father of Jim?
% Query: father(john, jim).
% Prolog will respond: Yes.
% Query: father(john, ann).
% Prolog will respond: Yes.
% Query: father(lisa, jim).
% Prolog will respond: No.
% Query: grandparent(john, ann). 
% Prolog will respond: Yes.
% Query: sibling(jim, ann).
% Prolog will respond: Yes.
