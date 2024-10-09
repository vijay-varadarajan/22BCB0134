% Define the initial and final states
initial_state([[1, 2, 3], [_, 4, 6], [7, 5, 8]]).
final_state([[1, 2, 3], [4, 5, 6], [7, 8, _]]).

% Breadth-First Search implementation
bfs(Start, Solution) :-
    bfs([[Start]], [], Solution).

bfs([[State | Path] | _], _, [State | Path]) :-
    final_state(State).

bfs([CurrentPath | OtherPaths], Visited, Solution) :-
    CurrentPath = [CurrentState | _],
    findall([NextState, CurrentState | Path],
            (move(CurrentState, NextState), \+ member(NextState, Visited)),
            NewPaths),
    append(OtherPaths, NewPaths, Paths),
    bfs(Paths, [CurrentState | Visited], Solution).

% Define possible moves
move(State, NextState) :-
    move_up(State, NextState);
    move_down(State, NextState);
    move_left(State, NextState);
    move_right(State, NextState).

% Move up
move_up(State, NextState) :-
    swap(State, X1, Y1, X2, Y2, NextState),
    X1 is X2 + 1,
    Y1 = Y2.

% Move down
move_down(State, NextState) :-
    swap(State, X1, Y1, X2, Y2, NextState),
    X1 is X2 - 1,
    Y1 = Y2.

% Move left
move_left(State, NextState) :-
    swap(State, X1, Y1, X2, Y2, NextState),
    X1 = X2,
    Y1 is Y2 + 1.

% Move right
move_right(State, NextState) :-
    swap(State, X1, Y1, X2, Y2, NextState),
    X1 = X2,
    Y1 is Y2 - 1.

% Swap two elements in the state
swap(State, X1, Y1, X2, Y2, NextState) :-
    nth0(X1, State, Row1),
    nth0(Y1, Row1, E1),
    nth0(X2, State, Row2),
    nth0(Y2, Row2, E2),
    replace(Row1, Y1, E2, NewRow1),
    replace(Row2, Y2, E1, NewRow2),
    replace(State, X1, NewRow1, TempState),
    replace(TempState, X2, NewRow2, NextState).

% Replace element in a list
replace([_|T], 0, E, [E|T]).
replace([H|T], I, E, [H|R]) :-
    I > 0,
    I1 is I - 1,
    replace(T, I1, E, R).

% Replace row in the state
replace([_|T], 0, E, [E|T]).
replace([H|T], I, E, [H|R]) :-
    I > 0,
    I1 is I - 1,
    replace(T, I1, E, R).