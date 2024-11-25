symptom(cold, [fever, runny_nose, headache]).
symptom(allergy, [red_eyes, runny_nose, itching]).
symptom(covid, [runny_nose, cough, fever, lost_taste]).

:- dynamic(user_has/1).

ask(Symptom) :-
    write('Do u have '), write(Symptom), write(' ? (yes/no): '), nl,
    read(Response),
    ( Response = yes -> assertz(user_has(Symptom)); true ).

count_matches(Disease, Count) :-
    symptom(Disease, Symptoms),
    findall(Symptom, (member(Sympton, Symptons), user_has(Symptom)), MatchingSymptoms),
    length(MatchingSymptoms, Count).

start :-
    retractall(user_has(_)),

    ask(fever),
    ask(runny_nose),
    ask(headache),
    ask(red_eyes),
    ask(itching),
    ask(cough),
    ask(lost_taste),

    findall([Count, Disease], (symptom(Disease, _), count_matches(Disease, Count)), Matches),
    sort(Matches, SortedMatches),
    reverse(SortedMatches, [[BestCount, BestDisease]|_]),
    ( BestCount > 0 -> write('You most likely have: '), write(BestDisease), nl
                        ; write('u dont hv any disease'), nl ).
