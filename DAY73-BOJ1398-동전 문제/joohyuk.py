import sys
from collections import deque
si = sys.stdin.readline


def main():
    T = int(si())
    coins, dp = [10, 25], [i for i in range(100)]
    for coin in coins:
        for value in range(coin, 100):
            dp[value] = min(dp[value], dp[value-coin]+1)
    while T:
        T -= 1
        car, ans = int(si()), 0
        while car:
            ans += dp[car % 100]
            car //= 100
        print(ans)


if __name__ == '__main__':
    main()
