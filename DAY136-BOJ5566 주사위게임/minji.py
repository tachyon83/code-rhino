import sys

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    maps = [0] + [int(sys.stdin.readline()) for _ in range(n)]
    dice = [0] + [int(sys.stdin.readline()) for _ in range(m)]
    cur = 1
    for i in range(1, m+1):
        cur += dice[i]
        if cur >= n:
            print(i)
            break
        cur += maps[cur]
        if cur >= n:
            print(i)
            break
