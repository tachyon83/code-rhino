import sys
si = sys.stdin.readline

n, cnt = int(si()), 0
col, diag = set(), set()


def isDiagOcc(r, c):
    global n, diag
    for m in range(-n+1, n):
        if (r+m, c+m) in diag or (r-m, c+m) in diag:
            return True
    return False


def backtrack(r, k):
    global n, cnt, col, diag
    if k == n:
        cnt += 1
        return
    for i in range(n):
        if i not in col and not isDiagOcc(r, i):
            col.add(i)
            diag.add((r, i))
            backtrack(r+1, k+1)
            diag.remove((r, i))
            col.remove(i)


backtrack(0, 0)
print(cnt)
