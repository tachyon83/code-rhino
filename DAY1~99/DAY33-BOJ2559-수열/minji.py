import sys
"""
sum(temps[i:i+k]) max
"""
def sol():
    t = sum(temps[0:k])
    ans = t
    for end in range(k, n):
        t += temps[end]
        t -= temps[end-k]
        if t > ans:
            ans = t
    print(ans)

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    temps = list(map(int, sys.stdin.readline().split()))

    sol()
