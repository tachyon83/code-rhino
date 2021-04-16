def check(r):
    for i in range(r):
        if col[i] == col[r]:
            return False
        if abs(r-i) == abs(col[r] - col[i]):
            return False
    return True

def solve(r):
    global ans
    if r == N:
        ans += 1
        return
    for i in range(N):
        col[r] = i
        if check(r):
            solve(r + 1)


ans = 0
N = int(input())
col = [0 for _ in range(N)]
solve(0)
print(ans)
