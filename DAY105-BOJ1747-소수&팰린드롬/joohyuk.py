import sys
from math import sqrt
si = sys.stdin.readline


def isPrime(n):
    if n == 1:
        return False
    v = int(sqrt(n))
    for e in range(2, v+1):
        if not n % e:
            return False
    return True


def isPalindrome(n):
    n = str(n)
    m, nl = len(n), len(n)//2
    for i in range(nl):
        if n[i] != n[m-1-i]:
            return False
    return True


n = int(si())
while not isPrime(n) or not isPalindrome(n):
    n += 1
print(n)
