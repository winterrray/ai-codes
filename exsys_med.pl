% Facts: Symptoms for different diseases
symptom(flu, fever).
symptom(flu, cough).
symptom(flu, body_ache).
symptom(flu, sore_throat).

symptom(cold, cough).
symptom(cold, sneezing).
symptom(cold, runny_nose).
symptom(cold, sore_throat).

symptom(covid19, fever).
symptom(covid19, cough).
symptom(covid19, shortness_of_breath).
symptom(covid19, loss_of_taste).

symptom(malaria, fever).
symptom(malaria, chills).
symptom(malaria, sweating).
symptom(malaria, headache).

% Disease diagnosis rule
disease(Patient, Disease) :-
    has_symptoms(Patient, Disease),
    write(Patient), write(' may have '), write(Disease), nl.

% Asking the user for symptoms
ask_symptom(Patient, Symptom) :-
    write('Does '), write(Patient), write(' have '), write(Symptom), write('? (yes/no)'), nl,
    read(Response),
    (Response == yes -> assert(has_symptom(Patient, Symptom)) ; true).

% Check if patient has all the required symptoms for a disease
has_symptoms(Patient, Disease) :-
    symptom(Disease, Symptom),
    has_symptom(Patient, Symptom),
    fail.
has_symptoms(_, _).

% Run the diagnosis
diagnose(Patient) :-
    retractall(has_symptom(Patient, _)),  % Clear any previous records
    ask_symptom(Patient, fever),
    ask_symptom(Patient, cough),
    ask_symptom(Patient, sore_throat),
    ask_symptom(Patient, body_ache),
    ask_symptom(Patient, sneezing),
    ask_symptom(Patient, runny_nose),
    ask_symptom(Patient, shortness_of_breath),
    ask_symptom(Patient, loss_of_taste),
    ask_symptom(Patient, chills),
    ask_symptom(Patient, sweating),
    ask_symptom(Patient, headache),
    disease(Patient, Disease) -> true; write('No matching disease found.'), nl.

