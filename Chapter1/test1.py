import math

n = 1
while 100 * math.pow(n, 2) >= math.pow(2, n):
    n = n + 1

print(n)