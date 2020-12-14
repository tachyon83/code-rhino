import sys

def sol():
    for i in range(n):
        ni = i
        for j in range(h):
            if check[j][ni]:
                ni += 1
            elif ni > 0 and check[j][ni-1]:
                ni -= 1
        if i != ni:
            return False
    return True

def bfs(res, x, y):
    cnt = 4
    if sol():
        cnt = min(cnt, res)
        return
    elif res == 3 or cnt <= res:
        return

    for i in range(x, h):
        k = y if i == x else 0
        for j in range(k, n-1):
            if not check[i][j] and not check[i][j+1]:
                check[i][j] = True
                bfs(res+1, i, j+2)
                check[i][j] = False
    return cnt if cnt < 4 else -1

if __name__ == "__main__":
    n, m, h  = map(int, sys.stdin.readline().split())
    check = [[False]*n for _ in range(h)]

    if m == 0:
        print(0)
        exit()

    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        check[a-1][b-1] = True

    print(bfs(0, 0, 0))


