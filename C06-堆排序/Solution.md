# 堆排序

## 6.1-1

Q：在高度为h的堆中，元素个数最多和最少分别是多少？

A：元素个数最多为$2^{h+1} - 1$，元素个数最少为$2^h$。

--------------------------------------

## 6.1-2

Q：证明：含$n$个元素的堆的高度为$\lfloor{\lg n}\rfloor$。

A：由(6.1-1)堆中元素个数最少为$2^h$，可得$2^h\leq n$，两边取对数得$h\leq \lg n$，因此含$n$个元素的堆的高度为$\lfloor{\lg n}\rfloor$。

--------------------------------------

## 6.1-3

Q：证明：在最大堆的任一子树中，该子树所包含的最大元素在该子树的根结点上。

A：假设某一最大堆的子树中，最大元素不在该子树的根结点上。那么对于该子树有$A[PARENT(max-element)]\leq A[max-element]$，与最大堆的性质矛盾，所以要么这个堆不是最大堆，要么最大元素在该子树的根结点上。从而可以推得，在最大堆的任一子树中，该子树所包含的最大元素在该子树的根结点上。

--------------------------------------


## 6.1-4

Q：假设一个最大堆的所有元素都不相同，那么该堆的最小元素应该位于哪里？

A：根据所有元素都不相同，和最大堆的性质可得，对于任意结点位置$i$，有$A[PARENT(i)]\gt A[i]$。设元素个数为$n$，最小元素位于位置$k$，满足$LEFT(k)>n$且$RIGHT(k)>n$，即某一叶结点上。

--------------------------------------


## 6.1-5

Q：一个已排好序得数组是一个最小堆吗？

A：是

--------------------------------------


## 6.1-6

Q：值为<23, 17, 14, 6, 13, 10, 1, 5, 7, 12>的数组是

不是

--------------------------------------


## 6.2-2
```
MIN-HEAPIFY(A, i)
    l = LEFT(i)
    r = RIGHT(i)
    if l <= A.heap-size and A[l] < A[i]
        smallest = l
    else
        smallest = i
    if i <= A.heap-size and A[r] < A[smallest]
        smallest = r
    if smallest != i
        exchange A[i] with A[smallest]
        MIN-HEAPIFY(A, smallest)
```

--------------------------------------


## 6.2-3

不会产生递归调用

--------------------------------------


## 6.2-4

叶子结点没有可比较的孩子结点

--------------------------------------


## 6.2-5
```
MAX-HEAPIFY(A, i)
    while i <= A.heap-size
        l = LEFT(i)
        r = RIGHT(i)
        if A[i] < A[l]
            largest = l
        else
            largest = i
        if A[r] > A[largest]
            largest = r
        if largest == i
            break
        else
            exchange A[i] with A[largest]
            i = largest
```

--------------------------------------


## 6.3-2

由于左右子树在构造时不为最大堆，因此从树的根结点开始往下构造最大堆时可能导致之前构造的最大堆失效。

--------------------------------------


## 6.4-3

升序和降序，时间复杂度相同都是nlgn

--------------------------------------


## 6.5-3
```
HEAP-MINIMUM(A)
    return A[1]

HEAP-EXTRACT-MIN(A)
    if A.heap-size < 1
        error "heap underflow"
    min = A[1]
    A[1] = A[A.heap-size]
    A.heap-size = A.heap-size - 1
    MIN-HEAPIFY(A, 1)
    return min

HEAP-DECREASE-KEY(A, i, key)
    if A[i] < key
        error "new key is larger than current key"
    A[i] = key
    while i > 1 and A[PARENT(i)] > A[i]
        exchange A[PARENT(i)] with A[i]
        i = PARENT(i)

MIN-HEAP-INSERT(A, key)
    A.heap-size = A.heap-size + 1
    A[A.heap-size] = $+\infty$
    HEAP-DECREASE-KEY(A, A.heap-size, key)
```

--------------------------------------


## 6.5-4

如果不设置为$-\infty$，那么原先数组中的值有可能会大于新设置的值，从而导致HEAP-INCREASE-KEY报错

--------------------------------------


## 6.5-6
```
HEAP-INCREASE-KEY(A, i, key)
    if A[i] > key
        error "new key is smaller than current key"
    while i > 1 and A[PARENT(i)] < key
        A[i] = A[PARENT(i)]
        i = PARENT(i)
    A[i] = key
```

--------------------------------------


## 6.5-7

以时间顺序为key，构造一个最小优先队列，入队用MIN-HEAP-INSERT，出队用HEAP-EXTRACT-MIN

以时间顺序为key，构造一个最大优先队列，入队用MAX-HEAP-INSERT，出队用HEAP-EXTRACT-MAX

--------------------------------------


## 6.5-8
```
HEAP-DELETE(A, i)
    if i > A.heap-size
        error "index out of range"
    exchange A[i] with A[A.heap-size]
    A.heap-size = A.heap-size - 1
    HEAPIFY(A, i)
```

--------------------------------------


## 6.5-9

思路：

A.以k个有序链表的首元素作为key，构造一个最小堆(BUILD-MIN-HEAP)

B.取走最小堆堆顶的元素，即该链表的首元素，此时堆顶元素变为该链表的下一个元素，若没有下一个元素，则删除该结点

C.对堆顶调用MIN-HEAPIFY，维持最小堆性质

D.重复过程B，直到堆中没有任何结点为止

E.按取走顺序构成的链表即为归并结果链表
