# 分治策略

## 4.1-1

Q：当A的所有元素均为负数时，FIND-MAXIMUM-SUBARRAY返回什么？

A：返回数组中最大的负数。

--------------------------------------

## 4.1-2

Q：对最大子数组问题，编写暴力求解方法的伪代码，其运行时间应该为$\Theta(n^2)$。

A：

```code
FIND-MAXIMUM-SUBARRAY-BRUTE(A, low, high):
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
    return (left, right, max)
```

--------------------------------------

## 4.1-3

Q：在你的计算机上实现最大子数组问题的暴力算法和递归算法。请指出多大的问题规模$n_0$是性能交叉点————从此之后递归算法将击败暴力算法？然后，修改递归算法的基本情况————当问题规模小于$n_0$时采用暴力算法。修改后，性能交叉点会改变吗？

A：$n_0$在28，修改后性能交叉点变大为30。参考程序[A1_3.py](Resources/A1_3.py)。

--------------------------------------

## 4.1-4

Q：假定修改最大子数组问题的定义，允许结果为空子数组，其和为0。你应该如何修改现有算法，使它们能允许空子数组为最终结果？

A：当返回总值为负数时，返回空子数组（例如用 low > high 表示空子数组）。

--------------------------------------

## 4.1-5

Q：使用如下思想为最大子数组问题设计一个非递归的、线性时间的算法。从数组的左边界开始，由左至右处理，记录到目前为止已经处理过的最大子数组。若已知$A[1..j]$的最大子数组，基于如下性质将解扩展为$A[1..j+1]$的最大子数组：$A[1..j+1]$的最大子数组要么是$A[1..j]$的最大子数组，要么是某个子数组$A[i..j+1](1\leq{i}\leq{j+1})$。在已知$A[1..j]$的最大子数组的情况下，可以在线性时间内找出形如$A[i..j+1]$的最大子数组。

A：

```
FIND-MAXIMUM-SUBARRAY-LINEAR(A):
    n = A.length
    max_sum = -INF
    sum = -INF
    for j = 1 to n
        if sum > 0
            sum = sum + A[j]
        else
            current_low = j
            sum = A[j]
        if sum > max_sum
            max_sum = sum
            low = current_low
            high = j
    return (low, high, max_sum)
```

--------------------------------------

## 4.2-2
```
SQUARE-MATRIX-MULTIPLY-STRASSEN(A,B):
    n = A.rows
    let C be a new n*n matrix
    if n == 1
        $c_{11} = a_{11} * b_{11}$
    else partition A, B and C as in equations(## 4.9)
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
```

--------------------------------------

## 4.2-7

分别计算(a + b)d,(c + d)a,(a - b)c

(ac - bd) == (c + d)a - (a + b)d

(ad + bc) == (c + d)a - (a - b)c

--------------------------------------

## 4.3-1

$T(n) \le c(n - 1)^2 + n$

$=cn^2 - 2cn + c + n$

$=cn^2 - (2c + 1)n + c$

$\le{cn^2}(c\ge1, n > 0)$

--------------------------------------

## 4.3-2

$T(n) \le c\lg{\lceil{n/2}\rceil} + 1$

$=c\lg(\frac{n}{2} + 1) + 1$

$=c\lg(\frac{n}{2}\frac{n+2}{n}) + 1$

$=c\lg{n} - c + c\lg{\frac{n+2}{n}} + 1$

$\le c\lg{n} - c + c\lg{\frac{5}{3}} + 1 (n\ge3)$

$\le c\lg{n} (c \ge (1-\lg{\frac{5}{3}})^{-1})$

--------------------------------------

## 4.3-3

$T(n) \ge 2c\lfloor{n/2}\rfloor \lg{\lfloor{n/2}\rfloor} + n$

$\ge 2c\frac{n-1}{2} \lg{\lfloor{n/2}\rfloor} + n$

$= cn \lg{\lfloor{n/2}\rfloor} - c \lg{\lfloor{n/2}\rfloor} + n$

$\ge cn \lg({\frac{n}{2} - 1}) - c \lg({\frac{n}{2} - 1}) + n$

$= cn \lg({\frac{n}{2} \frac{n-2}{n}}) - c \lg({\frac{n}{2} \frac{n-2}{n}}) + n$

$= cn \lg n - cn + cn \lg \frac{n-2}{n} - c \lg n + c - c \lg \frac{n-2}{n} + n$

$\ge cn \lg n (c > \frac{1}{2}, n \ge 4)$

