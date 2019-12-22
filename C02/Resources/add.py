def add(A, B):
    C = []
    result = 0
    for i in range(len(A), 0, -1):
        move = (len(A) - i)
        bitn = 1 << move
        result = result + A[i - 1] * bitn + B[i - 1] * bitn
        C.insert(0, (result >> move) % 2)
    if result > 1 << len(A):
        C.insert(0, 1)
    else:
        C.insert(0, 0)
    return C


def main():
    A = [0,0,0,0,1,0,0,1]
    B = [1,1,0,1,1,0,1,1]
    C = add(A,B)
    print(C)

main()
    