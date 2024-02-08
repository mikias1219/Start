% Facts about diseases
disease(flu).
disease(cold).

% Facts about symptoms
symptom(flu, cough).
symptom(cold, runny_nose).
symptom(cold, sneezing).

% Facts about treatments
treatment(flu, 'Get plenty of rest and drink fluids. Take over-the-counter pain relievers to reduce fever and relieve aches.').
treatment(cold, 'Drink plenty of fluids, get rest, and use over-the-counter cold medications to relieve symptoms.').

% Predicate to diagnose diseases based on symptoms
diagnose(Symptoms, Diseases, Treatments) :-
    findall(Disease, (
        disease(Disease),
        symptom(Disease, Symptom),
        member(Symptom, Symptoms)
    ), Diseases),
    findall(Treatment, (member(Disease, Diseases), treatment(Disease, Treatment)), Treatments).

% Main menu and choice processing
main_menu :-
    writeln('Medical Diagnostic System'),
    writeln('1. Enter symptoms'),
    writeln('2. Get diagnosis'),
    writeln('3. Exit'),
    read_option.

read_option :-
    write('Enter your choice: '),
    read(Choice),
    process_choice(Choice).

process_choice(1) :-
    enter_symptoms,
    main_menu.

process_choice(2) :-
    retrieve_symptoms(Symptoms),
    (
        Symptoms = [] ->
            writeln('Please enter symptoms first.'),
            main_menu
        ;
            diagnose(Symptoms, Diseases, Treatments),
            (
                Diseases = [] ->
                    writeln('No matching disease found. Please enter valid symptoms.'),
                    main_menu
                ;
                    write('Diagnosis: '), write(Diseases), nl,
                    write('Treatment: '), write(Treatments), nl,
                    main_menu
            )
    ).

process_choice(3) :-
    writeln('Exiting...').

% Predicate to enter symptoms
enter_symptoms :-
    writeln('Enter symptoms (comma-separated):'),
    read(Symptoms),
    split_string(Symptoms, ",", "", SymptomList),
    assertz(symptoms(SymptomList)).

% Predicate to retrieve symptoms
retrieve_symptoms(Symptoms) :-
    retract(symptoms(Symptoms)),
    !.

retrieve_symptoms([]).