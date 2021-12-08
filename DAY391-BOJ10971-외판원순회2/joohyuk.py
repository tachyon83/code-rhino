import sys
si = sys.stdin.readline


class TSP:
    def __init__(self, n):
        self.n = n
        self.W = []
        self.big = float('inf')
        self.dp = [[0 for _ in range(1 << n)]for _ in range(n)]
        self.all = (1 << n)-1

    def insert(self, l):self.W.append(l)
    def solve(self):print(self.tsp(1, 0))

    def tsp(self, mask, start):
        if self.dp[start][mask]:
            return self.dp[start][mask]
        if mask == self.all:
            if not self.W[start][0]:return self.big
            self.dp[start][mask] = self.W[start][0]
            return self.dp[start][mask]

        self.dp[start][mask] = self.big
        for e in range(self.n):
            if (1 << e) & mask or not self.W[start][e]:continue
            self.dp[start][mask] = min(self.dp[start][mask], self.W[start][e] +
                                       self.tsp(mask | (1 << e), e))
        return self.dp[start][mask]

n = int(si())
tsp = TSP(n)
for _ in range(n):tsp.insert([int(e) for e in si().split()])
tsp.solve()
