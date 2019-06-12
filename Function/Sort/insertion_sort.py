
def insertion_sort(A):
    print(A)
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
        print(A)

def test():
    A = [5,2,4,6,1,3]
    print("原数据")
    print(A)
    insertion_sort(A)
    print("排序后数据")
    print(A)

def test1():
    A = [31, 41, 59, 26, 41, 58]
    insertion_sort(A)


test1()