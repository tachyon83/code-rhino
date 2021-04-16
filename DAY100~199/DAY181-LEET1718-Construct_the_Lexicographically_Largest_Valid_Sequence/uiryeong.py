class Solution:
    def __init__(self):
        self.size, self.dp = 0, []
        self.ans = []

    def constructDistancedSequence(self, n: int) -> List[int]:
        self.size = n * 2 - 1
        self.dp = [0] * self.size
        self.dfs(0, [i for i in range(n, 0, -1)])
        return self.ans

    def dfs(self, idx, num):
        if self.ans:
            return

        while idx < self.size and self.dp[idx] != 0:
            idx += 1

        if idx == self.size:
            self.ans = list(self.dp)
            return

        if self.size - idx <= num[0] != 1:
            return

        for i in range(len(num)):
            if num[i] != 1:
                if self.dp[idx + num[i]] == 0:
                    self.dp[idx] = self.dp[idx + num[i]] = num[i]
                    self.dfs(idx + 1, num[: i] + num[i + 1:])
                    self.dp[idx] = self.dp[idx + num[i]] = 0
            else:
                self.dp[idx] = num[i]
                self.dfs(idx + 1, num[: i] + num[i + 1:])
                self.dp[idx] = 0
