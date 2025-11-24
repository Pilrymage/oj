NB. 脚本、函数、文件

NB. 文本是一个字符列表，包括换行符LF
txt =: 0 : 0
What is called a "script" is
a sequence of lines of J.
)

NB. 长度55，秩1，两个换行符
echo ($ txt) , (# $ txt) , (+/ txt = LF)

NB. 脚本是多行的语句
script =: 0 : 0
t =: T - 32
t * 5 % 9
)

do =: 0 !: 1 NB. 一个内置的 j 动词，可以执行脚本
NB. 这个 do 动词来自于（外部）合取，就像系统调用一样
NB. 左参数指定执行脚本的组，右脚本指定该组的特定成员（脚本）
T =: 212
do script

NB. 0 : 0 解释为“一个字符串如下”
NB. 3 : 0 解释为“一个动词如下”
NB. 这就显式定义了一个过程函数（显函数）
Celsius =: 3 : 0
t =: y - 32
t * 5 % 9
)

NB. 使用的参数 y 默认作为右参数传入
NB. 如果使用 x，它是左参数
echo Celsius 32 212

NB. 注意内部定义的变量t的赋值是全局作用域的
NB. 我们特别地有一个局部变量的赋值
NB. 而 x 和 y 默认局部变量
Celsius =: 3 : 0
t =. y - 32
t * 5 % 9
)

NB. 以下的 “4” 用于产生双目运算
posdiff =: 4 : 0
larger  =. x >. y
smaller =. x <. y
larger - smaller 
)

NB. 写作单行脚本也可以
PosDiff =: 4 : '(x >. y) - (x <. y)'

NB. 控制结构
   volume =: 3 : 0
if.   3 = # y
do.   * / y
else. 'ERROR'
end.
)

NB. 明确指出变量 x，y 的函数是显函数
NB. 相对地，不写出 x y 的是隐函数

echo Celsius (9!:3) 5

NB. 读取脚本或字符串的方式
F =: 'c:\temp\myscript.ijs'   
0!:1 < F

NB. j 语言以同样的方式在初期加载一个配置文件