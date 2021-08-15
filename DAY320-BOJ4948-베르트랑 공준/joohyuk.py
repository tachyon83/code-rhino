import sys
import bisect
from math import sqrt


def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(sqrt(n))+1):
        if not n % i:
            return False
    return True


v, pn = 123456, []
for e in range(1, v*2+1):
    if isPrime(e):
        pn.append(e)

for n in sys.stdin:
    n = int(n)
    if not n:
        break
    print(bisect.bisect_right(pn, 2*n)-bisect.bisect_left(pn, n+1))
