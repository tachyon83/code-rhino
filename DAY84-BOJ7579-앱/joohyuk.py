import sys
si = sys.stdin.readline

n, k = [int(e) for e in si().split()]
dp, a = [[0, set()]for _ in range(k+1)], []
for _ in range(n):
    a.append([int(e) for e in si().split()])
a.sort()

for i in range(k+1):
    for j in range(n):
        if a[j][0] > i:
            break
        elif j not in dp[i-a[j][0]][1]:
            if dp[i-a[j][0]][0]+a[j][1] > dp[i][0]:
                dp[i][0] = dp[i-a[j][0]][0]+a[j][1]
                dp[i][1] = (dp[i-a[j][0]][1]).union({j})
print(dp[k][0])
