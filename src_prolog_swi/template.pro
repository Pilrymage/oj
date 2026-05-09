hello_program :-
    read(Name),             % 读取输入并赋值给匿名变量，表示不关心输入具体内容 [12, 13]
    write('Hello, '), % 在输出设备打印字符串 [4, 6]
    write(Name),
    nl.                  % 换行 [3, 4]

?- hello_program.