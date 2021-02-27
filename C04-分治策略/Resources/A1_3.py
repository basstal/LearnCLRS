from random import randint
import time

def FIND_MAXIMUM_SUBARRAY_BRUTE(A, low, high):
    max = float('-inf')
    left = low
    right = high
    for i in range(low, high + 1):
        sum = 0
        for j in range(i, high + 1):
            sum = sum + A[j]
            if sum > max:
                max = sum
                left = i
                right = j
    return left, right, max


def FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high):
    left_sum = float('-inf')
    sum = 0
    max_left = mid
    max_right = mid
    for i in range(mid, low - 1, -1):
        sum = sum + A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i

    right_sum = float('-inf')
    sum = 0
    for j in range(mid + 1, high + 1):
        sum = sum + A[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j
        
    return max_left, max_right, left_sum + right_sum


def FIND_MAXIMUM_SUBARRAY(A, low, high):
    if high == low:
        return low, high, A[low]
    else:
        mid = (low + high) // 2
        left_low, left_high, left_sum = FIND_MAXIMUM_SUBARRAY(A, low, mid)
        right_low, right_high, right_sum = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)
        cross_low, cross_high, cross_sum = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

def FIND_MAXIMUM_MIXED(A, low, high):
    if high > 27:
        FIND_MAXIMUM_SUBARRAY(A, low, high)
    else:
        FIND_MAXIMUM_SUBARRAY_BRUTE(A, low, high)

            
def generate_A(size):
    if size is None:
        size = int(input('Enter a number for sequence size: '))
    A = []
    half = size // 2
    hasPositive = False
    for i in range(0, size):
        value = randint(0, size) - half
        A.append(value)
        if value > 0:
            hasPositive = True
    if not hasPositive:
        return generate_A(size)
    return A

def main():
    avg = 0
    for r in range(0, 1000):
        for size in range(1, 100):
            A = generate_A(size)
            high = len(A) - 1
            start_proc = time.time()
            FIND_MAXIMUM_SUBARRAY_BRUTE(A, 0, high)
            end_proc = time.time()
            brute_time = end_proc - start_proc

            start_proc = time.time()
            # FIND_MAXIMUM_SUBARRAY(A, 0, high)
            FIND_MAXIMUM_MIXED(A, 0, high)
            end_proc = time.time()
            recursive_time = end_proc - start_proc
            if recursive_time - brute_time > 0:
                avg = avg + size
                break
    avg /= 1000
    print(avg)

    return 0

main()