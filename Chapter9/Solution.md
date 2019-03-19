9.2-1

长度为0，则q=r或q=p，k=1或k=r-p+1，推得$i\nleq1$且$i\ngeq{r-p+1}$，因此大小为0不会被调用。

9.2-2

因为$X_k$是包含较小元素的一边，自然$X_k$和$T(max(k-1, n-k))$是独立的。

9.2-3
```
RANDOMIZED-SELECT(A,p,r,i):
    if p == r
        return A[p]
    q = RANDOMIZE-PARTITION(A,p,r)
    k = q - p + 1
    while i != k
        if i < k
            q = RANDOMIZED-PARTITION(A,p,q-1)
        else
            p = q + 1
            q = RANDOMIZED-PARTITION(A,q+1,r)
        k = q - p + 1
```

9.2-4

从9~1，9个数每个数都刚好依次被RANDOMIZED-SELECT选中。

9.3-1

由$\frac{2}{3}n+4$推得如果分成每组3个元素，$T(n)\leq{cn}$将不成立，因此运行时间将不是线性的。

9.3-2

9.3-3

先进行一次最坏情况下为$\Omicron(n)$时间复杂度的中位数选择，然后将改中位数作为快速排序的key。总的复杂度不超过$\Omicron(n\lg{n})$。

9.3-4
