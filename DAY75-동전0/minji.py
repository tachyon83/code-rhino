import sys

def sol(c):
    cnt = 0
    for i in coin[::-1]:
        if i <= c and c % i >= 0:
            a = c // i
            c -= (i * a)
            cnt += a
        if c == 0:
            break
    return cnt

if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().split())
    coin = []
    for i in range(n):
        coin.append(int(sys.stdin.readline()))

    print(sol(k))
