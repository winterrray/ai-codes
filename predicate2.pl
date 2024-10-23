% Facts about countries and their capitals
capital(paris, france).
capital(london, uk).
capital(berlin, germany).
capital(rome, italy). 
capital(madrid, spain).
capital(athens, greece).
capital(beijing, china).
capital(tokyo, japan).
capital(new_delhi, india).

% Facts about languages spoken in countries
language(france, french).
language(uk, english).
language(germany, german). 
language(italy, italian).
language(spain, spanish).
language(greece, greek). 
language(china, chinese).
language(japan, japanese).
language(india, hindi).

% Rules for identifying countries with the same language 
same_language(X, Y) :- language(X, L), language(Y, L), X \= Y.

% Rules for identifying neighboring countries
neighbor(france, spain). 
neighbor(france, germany).
neighbor(germany, belgium).
neighbor(germany, netherlands).
neighbor(italy, france). 
neighbor(italy, austria).
neighbor(italy, switzerland).

% ?- capital(Capital, france).
% % Expected Output: Capital = paris.
% ?- language(uk, Language).
% % Expected Output: Language = english.
% ?- same_language(italy, Country).
% % Expected Output: Country = france, Country = switzerland.
% ?- neighbor(germany, Neighbor).
% % Expected Output: Neighbor = belgium, Neighbor = netherlands.
