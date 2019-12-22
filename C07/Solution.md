7.1-2
```
PARTITION(A, p, r)
    x = A[r]
    i = p - 1
    mid = true
    for j = p to r - 1
        if A[j] != x
            mid = false
        if A[j] $\le$ x
            i = i + 1
            exchange A[i] with A[j]
    exchange A[i + 1] with A[r]
    if mid
        return (p + r) / 2
    else
        return i + 1
```

7.1-3

for循环对每个元素操作一次，其他均为常数时间的操作，因此时间复杂度为$\Theta(n)$

7.1-4

修改if判断的$\le$符号为$\ge$

7.2-2

$\Omicron(n^2)$

7.2-3

由于数组A包含的元素不同，并且已按照降序排列，每次PARTITION过程得到两个不平衡（n - 1 : 0)的子数组，PARTITION过程需要$\Theta(n)$，将会有n次PARTITION过程，因此QUICKSORT的时间复杂度为$\Theta(n^2)$

7.3-1

因为随机化算法出现最坏运行时间的概率极低

7.3-2

最坏情况下$\Theta(n)$，最好情况下$\Theta(\lceil\lg n\rceil)$

7.4-3

对$q^2+(n - q - 1)^2$，展开得到$2q^2 - 2(n - 1)q + (n-1)^2$，对q求导得到$4q-2(n-1)$

可知，当$4q-2(n-1) = 0$时，上式取极小值

因q=0,1,...,n - 1，所以当q=0时n=1，极小值是该式唯一的值，因此也是最大值

当q=n-1时，$2(n - 1)>0$，因此函数在q上单调递增，q最大时取最大值

所以当q=0或q=n-1时，$q^2+(n - q - 1)^2$取得最大值