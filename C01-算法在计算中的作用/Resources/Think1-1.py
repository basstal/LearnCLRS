import math
import random

times = {
    "second": 1000,
    "minute": 60000,
    "hour": 3600000,
    "day": 86400000,
    "month": 2592000000,
    "year": 31104000000,
    "centary": 3110400000000,
}
jump = [1, 10, 100, 1000, 10000, 100000]

lgn = "|"
sqrtn = "|"
num = "|"
nlgn = "|"
npow2 = "|"
npow3 = "|"
base2pown = "|"
nfactorial = "|"

basenlgn = 1
basenfactorial = 1
lastBasenlogn = 0


def calnlgn(val):
    global basenlgn
    global lastBasenlogn
    max = len(jump) - 1
    while max >= 0 and basenlgn * math.log2(basenlgn) < val:
        lastBasenlogn = basenlgn
        basenlgn += jump[max]
        if basenlgn * math.log2(basenlgn) > val:
            max -= 1
            basenlgn = lastBasenlogn
            
    return lastBasenlogn

def calnfactorial(val):
    global basenfactorial
    while math.factorial(basenfactorial) < val:
        basenfactorial += 1
    if math.factorial(basenfactorial) == val:
        return basenfactorial
    return basenfactorial - 1


for key, t in times.items():
    print("do %s, %s" % (key, t))

    lgn += "$2^{}$|".format(t)
    print("sqrtn")
    sqrtn += "${}$|".format(math.pow(t, 2))

    print("num")
    num += "${}$|".format(t)
    print("nlgn")
    nlgn += "${}$|".format(calnlgn(t))
    print("npow2")
    npow2 += "${}$|".format(int(math.sqrt(t)))

    print("npow3")
    npow3 += "${}$|".format(int(math.pow(t, 1 / 3)))

    print("base2pown")
    base2pown += "${}$|".format(int(math.log2(t)))

    print("nfactorial")
    nfactorial += "${}$|".format(calnfactorial(t))

    print("finished %s, %s" % (key, t))

print(lgn)
print(sqrtn)
print(num)
print(nlgn)
print(npow2)
print(npow3)
print(base2pown)
print(nfactorial)