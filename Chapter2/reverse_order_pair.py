import math

def reverse_order_pair(A, p, r):
    rp = 0
    if p < r:
        q = math.floor((p + r)/2)
        rp = rp + reverse_order_pair(A,p,q)
        rp = rp + reverse_order_pair(A,q+1,r)
        rp = rp + reverse_order_merge(A,p,q,r)
    return rp

def reverse_order_merge(A,p,q,r):
    n1 = q - p + 1
    n2 = r - q
    L = []
    R = []
    for i in range(0, n1):
        L.append(A[p + i])
    for j in range(0, n2):
        R.append(A[q + j + 1])
    
    L.append(float('-inf'))
    R.append(float('-inf'))
    i = 0
    j = 0
    rp = 0
    for k in range(p, r + 1):
        # print("{0}, {1}, {2}".format(k, i, j))
        if L[i] > R[j]:
            rp = rp + n2 - j
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1 
    return rp

def main():
    A = [7, 2, 3, 8, 6, 1]
    print(reverse_order_pair(A, 0, len(A) - 1))


main()