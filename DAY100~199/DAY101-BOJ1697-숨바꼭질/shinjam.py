from collections import deque

N, K = map(int, input().split())
dp = [0] * 100_001
size = 100_001
q = deque([N])



while True:
    x = q.popleft()

    if x == K:
        print(dp[K])
        break
    for c in x-1, x+1, x*2:
        if 0<=c<size and dp[num]!=0:
            dp[c] = dp[x]+1
            q.append(c)
