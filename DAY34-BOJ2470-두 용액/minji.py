import sys
"""
combination x
full search x
"""

def sol(t):
    start, end = 0, n-1
    min_sum = t[start] + t[end]
    a, b = start, end
    while start < end:
        tmp = t[start] + t[end]
        if abs(tmp) < abs(min_sum):
            min_sum, a, b = tmp, start, end
            if min_sum == 0:
                break
        if tmp < 0:
            start += 1
        else:
            end -= 1
    print(t[a], t[b])

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    t = list(map(int, sys.stdin.readline().split()))
    t = sorted(t)
    sol(t)
