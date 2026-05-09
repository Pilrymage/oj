256 constant MAX-LINE
create line-buffer MAX-LINE allot
variable case#

: formula 
    s>f f2* 0.25e f+ fsqrt 0.5e f- floor f>s
;

: getline line-buffer MAX-LINE stdin read-line throw ( u flag ) ;
: evaluate-line line-buffer swap evaluate ;

: solve 
    evaluate-line formula . cr
;
    
: .case-header ( n -- ) ." Case " 0 <# [char] : hold #s #> type space ;
      
: process-given-testcase-number
    getline if
    evaluate-line 0 ?do
      getline if solve else drop then
    loop
  else drop \ 处理空文件情况
  then ;
: process-terminate-by-eof
    begin
    getline while
    solve repeat
    drop
;

: process-until-0
    begin
        getline while ( 检查 EOF )
        dup while  ( 直接测试数字 n：如果 n 非零则进入循环体，n 为 0 则跳至 REPEAT 之后 )
            solve repeat
        drop ( 丢弃 evaluate 产生的 n 或 read-line 的计数 )
    then
;
        
process-given-testcase-number