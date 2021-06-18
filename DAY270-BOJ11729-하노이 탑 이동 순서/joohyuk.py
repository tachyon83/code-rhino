import sys
si = sys.stdin.readline

def h(n, s, m, e):
    if not n-1:
        print(s, e)
        return
    h(n-1, s, e, m)
    h(1, s, m, e)
    h(n-1, m, s, e)

n = int(si())
print(2**n-1)
h(n, 1, 2, 3)
