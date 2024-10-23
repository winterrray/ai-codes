% Define diseases and their symptoms
disease(flu) :- has_symptoms([fever, headache, cough, body_ache, sore_throat]).
disease(cold) :- has_symptoms([sneezing, sore_throat, runny_nose, cough]).
disease(covid_19) :- has_symptoms([fever, cough, loss_of_taste_or_smell, breathing_difficulty, fatigue]).
disease(migraine) :- has_symptoms([headache, nausea, sensitivity_to_light, sensitivity_to_sound]).
disease(strep_throat) :- has_symptoms([fever, sore_throat, swollen_lymph_nodes, white_patches_in_throat]).
disease(allergy) :- has_symptoms([sneezing, runny_nose, itchy_eyes, cough]).
disease(appendicitis) :- has_symptoms([abdominal_pain, nausea, vomiting, fever, loss_of_appetite]).

% Check if the patient has all symptoms from a list
has_symptoms([]).
has_symptoms([Symptom | Rest]) :-
    symptom(Symptom),
    has_symptoms(Rest).

% Define symptoms and their questions
symptom(fever) :- ask('Do you have a fever?').
symptom(headache) :- ask('Do you have a headache?').
symptom(cough) :- ask('Are you coughing?').
symptom(body_ache) :- ask('Do you have body aches?').
symptom(sore_throat) :- ask('Do you have a sore throat?').
symptom(runny_nose) :- ask('Do you have a runny nose?').
symptom(sneezing) :- ask('Are you sneezing?').
symptom(loss_of_taste_or_smell) :- ask('Have you lost your sense of taste or smell?').
symptom(breathing_difficulty) :- ask('Are you having difficulty breathing?').
symptom(fatigue) :- ask('Do you feel fatigued or tired?').
symptom(nausea) :- ask('Do you feel nauseous?').
symptom(sensitivity_to_light) :- ask('Are you sensitive to light?').
symptom(sensitivity_to_sound) :- ask('Are you sensitive to sound?').
symptom(swollen_lymph_nodes) :- ask('Do you have swollen lymph nodes?').
symptom(white_patches_in_throat) :- ask('Do you have white patches in your throat?').
symptom(itchy_eyes) :- ask('Do you have itchy eyes?').
symptom(abdominal_pain) :- ask('Do you have abdominal pain?').
symptom(vomiting) :- ask('Are you vomiting?').
symptom(loss_of_appetite) :- ask('Have you lost your appetite?').

% Asking mechanism
ask(Question) :-
    format('~w (yes/no): ', [Question]),
    read(Reply),
    (Reply == yes ; Reply == y).

% Start the diagnosis process
diagnose :-
    ( disease(flu) -> write('You may have the flu. Drink fluids, rest, and consult a doctor if symptoms persist.') ;
      disease(cold) -> write('You may have a common cold. Rest and stay hydrated.') ;
      disease(covid_19) -> write('You may have COVID-19. Isolate yourself and get tested. Consult a healthcare provider.') ;
      disease(migraine) -> write('You may be experiencing a migraine. Rest in a dark, quiet room.') ;
      disease(strep_throat) -> write('You may have strep throat. Consult a doctor for a throat swab and treatment.') ;
      disease(allergy) -> write('You may be experiencing an allergy. Consider taking antihistamines.') ;
      disease(appendicitis) -> write('You may have appendicitis. Seek immediate medical attention.') ;
      write('Sorry, I could not diagnose your condition with the given symptoms.')
    ).