% base case
create_list(Head, [], [Head]).

% recursive step
create_list(Head, Tail, [Head | Tail]).
