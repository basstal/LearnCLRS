# 2.1-1

[insertion_sort.py](../Function/Sort/insertion_sort.py)

# 2.1-2

[insertion_sort.py](./insertion_sort1.py)

# 2.1-3

```
LINER-FIND(A,v):
    result = NIL
    for i = 1 to A.length
        if A[i] == v
            result = i
            break
    return result
```

循环不变式：所有下标小于i当前值的数都不是所求的下标值。

初始化：该情况下i=1,下标最小，所以情况为真。

保持：对于某次迭代，下标值为i。小于i的下标对应数组中的值与v都不相等，且if语句判断当前下标对应数组中的值A[i]与v的相等性。如果相等则程序返回下标值i，即所求的值，否则迭代继续执行。此时下标值比上次迭代下标值大1，且所有小于该下标值的数组中值都不等于v。

终止：当下标值大于数组长度时终止，此时所有小于该下标值的数组中的值都不等于v，按要求返回NIL。

# 2.1-4

输入：两个代表n位二进制数的序列A和B，其中$A=<a_1,a_2,…,a_n>$，$B=<b_1,b_2,…,b_n>$。

输出：一个代表n+1位二进制数的序列C，其中$C=<c_1,c_2,…,c_n,c_{n+1}>$。

```
ADD(A,B):
    result = 0
    for i = A.length downto 1
        mvbit = A.length - i
        bitn = 1 << mvbit
        result = result + A[i] * bitn + B[i] * bitn
        C[i] = (result >> mvbit) % 2
    if result > (1 << A.length)
        C[1] = 1
    else
        C[1] = 0
```

[add.py](./add.py)

# 2.2-1

$\Theta({n^3})$

# 2.2-2

```
SELECTION-SORT(A):
    for i = 1 to A.length-1
        toSwap = A[i]
        for idx = i + 1 to A.length
            if A[i] > A[idx]
                A[i] = A[idx]
                A[idx] = toSwap
                toSwap = A[i]
```

循环不变式：每次循环结束后将序列中第i小的元素放置在序列的第i个位置上

因为循环不变式，算法只需要n-1次循环将前n-1小的元素按序放置在前n-1个位置上，于是自然有第n个位置放置的是第n小（即最大）的元素。

最好与最坏情况运行时间都是：$\Theta({n^2})$

# 2.2-3

平均需要检查数组一半的元素：$\Theta({n^2})$

最坏需要检查全部的元素：$\Theta({n^2})$

# 2.2-4

从算法上，降低常量因子的值，即使用尽量少的步长来执行算法逻辑。

# 2.3-1

做图过程略；

2.3-2

归并排序的合并过程
```
MERGE(A,p,q,r):
n1 = q - p + 1
n2 = r - q
let L[1...n1] and R[1...n2] be new array
for i = 1 to n1
    L[i] = A[p + i - 1]
for j = 1 to n2
    R[j] = A[q + i]
i = 1
j = 1
k = p
while i <= n1 and j <= n2
    if L[i] <= R[j]
        A[k] = L[i]
        i = i + 1
    else A[k] = R[j]
        j = j + 1
    k = k + 1
while i <= n1
    A[k] = L[i]
    i = i + 1
    k = k + 1
while j <= n2
    A[k] = R[j]
    j = j + 1
    k = k + 1
```
2.3-3

已证明；

2.3-4

公式略；

2.3-5

二分查找
```
BINARY_SEARCH(A,v)迭代版本:
low = 1
high = A.length
while low <= high
    mid = (low + high) / 2
    if A[mid] == v
        return mid
    elseif A[mid] < v
        low = mid + 1
    else high = mid - 1
v = NIL
```

2.3-6

理论上可行，但没有合适的数据结构，在插入时需要移动插入位置之后的元素，如果使用数组则挪动元素还是需要与n线性相关的时间，如果使用链表则不能使用直接下标索引来进行二分查找，而遍历链表需要的也是n线性相关的时间。

2.3-7

设a+b=x,a和b都属于S，算法对于任意的a属于S，二分查找x-b。