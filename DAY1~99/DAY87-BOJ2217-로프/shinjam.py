import sys
input = sys.stdin.readline
N = int(input())
ROPES = list(int(input()) for _ in range(N))
ROPES.sort()
ans = 0
for i in range(N):
    ans = max(ans, ROPES[i]*(N-i))
print(ans)
