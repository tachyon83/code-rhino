import sys
si = sys.stdin.readline

dna, sz = si()[:-1], int(5e2)+1
l, dp = len(dna), [[-1 for _ in range(sz)]for _ in range(sz)]
p = ['at', 'gc']


def solve(s, e):
    global dna, dp, p

    if s >= e:
        return 0
    if dp[s][e] != -1:
        return dp[s][e]

    temp = 0
    if (dna[s] == p[0][0] and dna[e] == p[0][1]) or (dna[s] == p[1][0] and dna[e] == p[1][1]):
        temp = 2+solve(s+1, e-1)

    for i in range(s, e):
        temp = max(temp, solve(s, i)+solve(i+1, e))
    dp[s][e] = temp
    return dp[s][e]


print(solve(0, l-1))
