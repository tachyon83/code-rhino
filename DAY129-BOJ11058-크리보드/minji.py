import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    dp = [num for num in range(n + 1)]
    
    for i in range(4, n+1):
        for j in range(1, i-2):
            dp[i] = max(dp[i], dp[i-1]+1, dp[i-(2+j)]*(1+j))
    print(dp[-1])
