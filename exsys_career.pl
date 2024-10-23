% Declare dynamic predicates
:- dynamic(interest/2).
:- dynamic(skill/2).

% Interests and skills for various careers
interest(john, technology).
interest(john, problem_solving).
interest(john, creativity).
interest(john, communication).

skill(john, coding).
skill(john, writing).
skill(john, critical_thinking).

% Career paths and required interests/skills
career(software_engineer) :-
    interest(_, technology),
    skill(_, coding).

career(writer) :-
    interest(_, creativity),
    skill(_, writing).

career(data_scientist) :-
    interest(_, technology),
    interest(_, problem_solving),
    skill(_, coding),
    skill(_, critical_thinking).

career(teacher) :-
    interest(_, communication),
    interest(_, helping_others),
    skill(_, writing).

career(artist) :-
    interest(_, creativity),
    interest(_, art).

% Asking about interests
ask_interest(Student, Interest) :-
    write('Are you interested in '), write(Interest), write('? (yes/no)'), nl,
    read(Reply),
    (Reply == yes -> assert(interest(Student, Interest)) ; true).

% Asking about skills
ask_skill(Student, Skill) :-
    write('Do you have the skill of '), write(Skill), write('? (yes/no)'), nl,
    read(Reply),
    (Reply == yes -> assert(skill(Student, Skill)) ; true).

% Suggest careers without repetition
suggest_career(Student) :-
    findall(Career, career(Career), Careers), % Collect all valid career options
    list_to_set(Careers, UniqueCareers),      % Remove duplicates
    suggest_career_list(Student, UniqueCareers).

% Helper predicate to print out career suggestions
suggest_career_list(_, []).
suggest_career_list(Student, [Career | Rest]) :-
    write(Student), write(', you could pursue a career as a '), write(Career), nl,
    suggest_career_list(Student, Rest).

% Career guidance system
career_guidance(Student) :-
    retractall(interest(Student, _)),
    retractall(skill(Student, _)),

    % Ask about interests
    ask_interest(Student, technology),
    ask_interest(Student, problem_solving),
    ask_interest(Student, creativity),
    ask_interest(Student, communication),
    ask_interest(Student, helping_others),
    ask_interest(Student, art),

    % Ask about skills
    ask_skill(Student, coding),
    ask_skill(Student, writing),
    ask_skill(Student, critical_thinking),

    % Suggest a career based on their answers
    suggest_career(Student).
