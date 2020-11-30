import sys

def knapsack():
    k = [[0 for _ in range(sum(costs)+1)] for _ in range(n+1)]

    ans = sum(costs)
    for i in range(1, n+1):
        byte, cost = bytes[i], costs[i]

        for j in range(1, sum(costs)+1):
            if j < cost:
                k[i][j] = k[i-1][j]
            else:
                k[i][j] = max(byte+k[i-1][j-cost], k[i-1][j])
            if k[i][j] >= m:
                ans = min(ans, j)
    return ans if m != 0 else 0


if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split()))
    bytes = [0] + [i for i in map(int, sys.stdin.readline().split())]
    costs = [0] + [i for i in map(int, sys.stdin.readline().split())]

    print(knapsack())
