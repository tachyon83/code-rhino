import sys
si = sys.stdin.readline

n = int(si())
m = int(si())
wrongBtns, ans = [e for e in si().split()], abs(n-100)


def check(s):
    global wrongBtns
    for c in s:
        if c in wrongBtns:
            return False
    return True


for e in range(0, 1000000+1):
    curr = str(e)
    if check(curr):
        ans = min(ans, len(curr)+abs(e-n))
print(ans)
