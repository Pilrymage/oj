square =: *: NB. 定义 verb：单目动词和双目动词
echo square 1 2 3 4

echo 'a' ,~ 'b' NB. 副词：反转函数的左右参数

double =: * & 2 NB. 合取：指定函数的右参数，将其变为单目函数
echo double 3

NB. j 的所有函数都可归类为四类：单目动词、双目动词、副词、合取。

sum =: +/
echo sum square 1 2 3
sumsq =: sum @: square NB. 复合函数
echo sumsq 1 2 3

NB. 单子与双子复合，参数数量按照最内层函数输入
echo 2 3 (sum @: * ) 1 100

NB. 习语看上去不符合语法，但你还是能简单理解它的含义
NB. 钩子 hook 由两个动词组成：双子钩单子，单子起预处理作用(hook)
echo 50 + 0.1 * 50 NB. 因为这两边的50是一样的参数，我想将它变作一个参数
echo (+ (0.1 & *)) 50

NB. 分叉 fork 由三个动词组成：单双单。
L =: 3 5 7 9
echo (sum L) % (# L) NB. 这是一个求平均数的方法
echo (sum % #) L

echo (<./ , >./) L NB. 求值域：即最小值和最大值

NB. 这些动词序列称为列车 train。

frac     =: % +/
percent  =: (100 & *) @: frac
round    =: <. @: (+ & 0.5)
comp     =: round @: percent
br       =: ,.  ;  (,. @: comp)
tr       =: ('Data';'Percentages') & ,:
display  =: tr @: br
echo display 3 1 4