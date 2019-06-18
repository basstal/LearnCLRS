import math

def merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    L = []
    R = []
    for i in range(0, n1):
        L.append(A[p + i])
    for j in range(0, n2):
        R.append(A[q + j + 1])

    L.append(float('inf'))
    R.append(float('inf'))
    i = 0
    j = 0
    for k in range(p, r + 1):
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

def merge_sort(A, p, r):
    if p < r:
        q = math.floor((p + r) / 2)
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)


def main():
    # A = [2,4,5,7,1,2,3,6]
    # merge(A, 0, 3, 7)
    # print(A)
    A = [2,3,6,3,4,6,7,2,1,4]
    merge_sort(A, 0, len(A) - 1)
    print(A)


main()