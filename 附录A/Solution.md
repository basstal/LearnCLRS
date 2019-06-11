# A.1-1

$\sum_{k=1}^n{(2k-1)}$

$=2\sum_{k=1}^n{k} - n$

$=2 * {\frac{1}{2}n(n+1)} - n$

$=n^2$

# A.1-2

# A.1-3

$由\sum_{k=0}^\infty{kx^k}=\frac{x}{(1-x)^2}两边对x微分并乘以x，可以得到\sum_{k=0}^{\infty}k^2x^k=\frac{x(1+x)}{(1-x)^3}，其中|x|<1$

# A.1-4

$\sum_{k=0}^{\infty}\frac{(k-1)}{2^k}=\sum_{k=0}^{\infty}k\frac{1}{2}^k-\sum_{k=0}^{\infty}\frac{1}{2}^k=2-2=0$

# A.1-5

# A.1-6

# A.1-7

$\log_2{(\prod_{k=1}^{n}{2*4^k})}=\sum_{k=1}^{n}{\log_2{2^{2k+1}}}=\sum_{k=1}^{n}2k+1=n^2+2n$

$因此\prod_{k=1}^{n}{2*4^k}=2^{n^2+2n}$

# A.1-8

$\log_2{(\prod_{k=2}^{n}{(1-\frac{1}{k^2})})}=\sum_{k=2}^{n}\log_2{(k+1)(k-1)k^{-2}}=\sum_{k=2}^{n}\log_2{(k+1)}+\sum_{k=2}^{n}\log_2{(k-1)}+\sum_{k=2}^{n}\log_2{k^{-2}}=\log_2{\frac{(n+1)!}{2}}+\log_2{(n-1)!}-2\log_2{n!}=\log_2{\frac{n+1}{2n}}$

$因此\prod_{k=2}^{n}{(1-\frac{1}{k^2})}=\frac{n+1}{2n}$