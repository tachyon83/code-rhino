import sys
si = sys.stdin.readline

n, m = int(si()), 0
w = [int(e) for e in si().split()]


def solve(w, t):
    global m
    if len(w) == 2:
        m = max(m, t)
        return
    for i in range(1, len(w)-1):
        solve(w[0:i]+w[i+1:], t+w[i-1]*w[i+1])


solve(w, 0)
print(m)
