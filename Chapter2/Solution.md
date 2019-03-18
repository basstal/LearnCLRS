2.1-1
```
	31 41 59 26 41 58	41为key大于31，41放置在原位置；
	31 41 59 26 41 58	59为key大于41，59放置在原位置；
	31 41 59 26 41 58	26为key，j为26的位置，26小于59，59放置在j，26小于41，41放置在j-1,26小于31,31放置在j-2，最后将26放置在j-3。
	26 31 41 59 41 58	41为key，j为41的位置，41小于59,59放置在j，41放置在j-1.
	26 31 41 41 59 58	58为key，58小于59,59放置在j，58放置在j-1.
	26 31 41 41 58 59	得到排序结果
```

2.1-2

插入排序
```
伪代码INSERTION-SORT(A)按照非升序排列：
for j = 2 to A.length
    key = A[j]
    i = j – 1
    while i > 0 and A[i] < key
        A[i+1] = A[i]
        i = i - 1
    A[i+1] = key
```

2.1-3

线性查找
```
LINER-FIND(A,v):
for i = 1 to A.length
    if A[i] == v
        return i
v = NIL
```

循环不变式：所有下标小于i当前值的数都不是所求的下标值。

初始化：该情况下i=1,下标最小，所以情况为真。

保持：对于某次迭代，下标值为i，小于i的下标对应数组中的值与v都不想等，且if语句判断当前下标对应数组中的值A[i]与v的相等性，如果相等则程序返回下标值i，即所求的值，否则迭代继续执行，此时下标值比上次迭代下标值大1,且所有小于该下标值的数组中值都不与v相等。

终止：当下标值大于数组长度时终止，此时所有小于该下标值的数组中对应位置的值都与v不相等，按要求置v=NIL。

2.1-4

输入：两个代表二进制的序列A和B，其中A=<a1,a2,…,an>,B=<b1,b2,…,bn>，a1~an和b1~bn取值范围为{0,1}。

输出：一个代表二进制的序列C，其中C=<c1,c2,…,cn,cn+1>,c1~cn+1取值范围为{0,1}。

将两个二进制数组A和B相加得到二进制数组C
```
ADD(A,B):
inc = 0
for i = A.length to 1
    if A[i] + B[i] == 2
        if  inc == 1
            C[i+1] = 1
        else C[i+1] = 0
        inc = 1
    elseif A[i] + B[i] == 1
        if  inc == 1
            C[i+1] = 0
        else C[i+1] = 1
    else
        if  inc == 1
            C[i+1] = 1
            inc = 0
        else C[i+1] = 0
C[i] = inc
return C
```

2.2-2

选择排序
```
SELECTION-SORT(A):
for i = 1 to A.length-1
    key = A[i]
    j = i
    min = A[j]
    for idx = j+1 to A.length
        if min > A[idx]
            j = idx
            min = A[idx]
    A[i] = A[j]
    A[j] = key
```

循环不变式：每次循环结束后将序列中第i小的元素放置在序列的第i个位置上

因为循环不变式，算法只需要n-1次循环将前n-1小的元素按序放置在前n-1个位置上，于是自然有第n个位置放置的是第n小（即最大）的元素。

2.2-4

降低一个算法的高阶项的增长率。

2.3-1

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