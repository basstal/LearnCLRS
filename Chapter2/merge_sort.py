def merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    L = []
    R = []
    for i in range(0, n1):
        L.append(A[p + i])
    for j in range(0, n2):
        R.append(A[q + j + 1])

    i = 0
    j = 0
    k = p
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
        k = k + 1

    while i < n1:
        A[k] = L[i]
        i = i + 1
        k = k + 1
    while j < n2:
        A[k] = R[j]
        j = j + 1
        k = k + 1

def main():
    A = [2,4,5,7,1,2,3,6]
    merge(A, 0, 3, 7)
    print(A)



main()