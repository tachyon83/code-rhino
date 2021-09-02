import sys
si = sys.stdin.readline

t, dp, cards = int(si()), 0, 0

def solve(s, e, turn):
    if s > e:return 0
    if not dp[s][e]:
        if turn:dp[s][e] = max(cards[s]+solve(s+1, e, False),cards[e]+solve(s, e-1, False))
        else:dp[s][e] = min(solve(s+1, e, True), solve(s, e-1, True))
    return dp[s][e]


while t:
    t -= 1
    n = int(si())
    dp = [[0 for _ in range(n)]for _ in range(n)]
    cards = [int(e) for e in si().split()]
    print(solve(0, n-1, True))
