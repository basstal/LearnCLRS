4.1-1
返回数组中最大的负数。

4.1-2
暴力求解最大子数组问题
FIND-MAXIMUM-SUBARRAY(A, low ,high):
max = -INF
left = low
right = high
for i = low to high
    sum = 0
    for j = i to high
        sum = sum + A[j]
        if sum > max
            max = sum
            left = i
            right = j
return (left,right, max)
    

4.1-3
见find_maximum_subarray_brute.c与find_maximum_subarray.c

4.1-4
在递归算法中，将left_max和right_max的初值改为0,最后添加判断如果结果为0,则left和right都为-1表示空子数组；

4.1-5
FIND-MAXIMUM-SUBARRAY-LINEAR(A,low,high):
oldmax = A[left]
left = low
right = high
for i = low to high
    max = -INF
    sum = 0
    right_low = i + 1
    for j = i + 1 downto right + 1
        sum = sum + A[j]
        if sum > max
            max = sum
            right_low = j
    if right_low == right + 1
        right = i + 1
        oldmax = oldmax + max
    else if max > oldmax
        oldmax = max
        left = right + 1
        right = i + 1
return (left,right,oldmax)


4.2-2

SQUARE-MATRIX-MULTIPLY-STRASSEN(A,B):
    n = A.rows
    let C be a new n*n matrix
    if n == 1
        $c_{11} = a_{11} * b_{11}$
    else partition A, B and C as in equations(4.9)
        $S_1 = B_{12} - B_{22}$
        $S_2 = A_{11} + A_{12}$
        $S_3 = A_{21} + A_{22}$
        $S_4 = B_{21} - B_{11}$
        $S_5 = A_{11} + A_{22}$
        $S_6 = B_{11} + B_{22}$
        $S_7 = A_{12} - A_{22}$
        $S_8 = B_{21} + B_{22}$
        $S_9 = A_{11} - A_{21}$
        $S_10 = B_{11} + B_{12}$
        $P_1 = SQUARE-MATRIX-MULTIPLY-STRASSEN(A_{11} , S_1)$
        $P_2 = SQUARE-MATRIX-MULTIPLY-STRASSEN(S_2 , B_{22})$
        $P_3 = SQUARE-MATRIX-MULTIPLY-STRASSEN(S_3 , B_{11})$
        $P_4 = SQUARE-MATRIX-MULTIPLY-STRASSEN(A_{22} , S_4)$
        $P_5 = SQUARE-MATRIX-MULTIPLY-STRASSEN(S_5 , S_6)$
        $P_6 = SQUARE-MATRIX-MULTIPLY-STRASSEN(S_7 , S_8)$
        $P_7 = SQUARE-MATRIX-MULTIPLY-STRASSEN(S_9 , S_10)$
        $C_{11} = P_5 + P_4 - P_2 + P_6$
        $C_{12} = P_1 + P_2$
        $C_{21} = P_3 + P_4$
        $C_{22} = P_5 + P_1 - P_3 - P_7$
    return C

4.2-7
分别计算(a + b)d,(c + d)a,(a - b)c
(ac - bd) == (c + d)a - (a + b)d
(ad + bc) == (c + d)a - (a - b)c

4.3-1
$T(n) \le c(n - 1)^2 + n$

$=cn^2 - 2cn + c + n$

$=cn^2 - (2c + 1)n + c$

$\le{cn^2}(c\ge1, n > 0)$

4.3-2
$T(n) \le c\lg{\lceil{n/2}\rceil} + 1$

$=c\lg(\frac{n}{2} + 1) + 1$

$=c\lg(\frac{n}{2}\frac{n+2}{n}) + 1$

$=c\lg{n} - c + c\lg{\frac{n+2}{n}} + 1$

$\le c\lg{n} - c + c\lg{\frac{5}{3}} + 1 (n\ge3)$

$\le c\lg{n} (c \ge (1-\lg{\frac{5}{3}})^{-1})$

4.3-3
$T(n) \ge 2c\lfloor{n/2}\rfloor \lg{\lfloor{n/2}\rfloor} + n$

$\ge 2c\frac{n-1}{2} \lg{\lfloor{n/2}\rfloor} + n$

$= cn \lg{\lfloor{n/2}\rfloor} - c \lg{\lfloor{n/2}\rfloor} + n$

$\ge cn \lg({\frac{n}{2} - 1}) - c \lg({\frac{n}{2} - 1}) + n$

$= cn \lg({\frac{n}{2} \frac{n-2}{n}}) - c \lg({\frac{n}{2} \frac{n-2}{n}}) + n$

$= cn \lg n - cn + cn \lg \frac{n-2}{n} - c \lg n + c - c \lg \frac{n-2}{n} + n$

$\ge cn \lg n (c > \frac{1}{2}, n \ge 4)$

