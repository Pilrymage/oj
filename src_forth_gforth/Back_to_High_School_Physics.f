256 constant MAX-LINE
create line-buffer MAX-LINE allot
      
: process-input
    begin
        line-buffer MAX-LINE stdin read-line throw ( u flag )
    while
        line-buffer swap evaluate
        * 2 * . cr
    repeat
    drop
;
process-input