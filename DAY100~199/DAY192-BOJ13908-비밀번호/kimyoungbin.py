import sys

def check():
    for h in hint:
        if not visit[int(h)]:
            return False
    return True
def solve(n, now_len):
    global cnt
    if n == now_len:
        if check():
            cnt += 1
    else:
        for i in range(10):
            visit[i] += 1
            solve(n, now_len + 1)
            visit[i] -= 1

cnt = 0
n, m = map(int, sys.stdin.readline().split())
hint = sys.stdin.readline().split()
visit = [0 for _ in range(10)]
solve(n, 0)
print(cnt)
