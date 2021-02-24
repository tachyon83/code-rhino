import sys

def sol():
    for l in range(n):
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if lst[i][j] == "Y" or (lst[i][l] == "Y" and lst[l][j] == "Y"):
                    ch[i][j] = 1


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    lst = []
    ch = [[0] * n for i in range(n)]
    for i in range(n):
        f = list(sys.stdin.readline().strip())
        lst.append(f)

    sol()

    res = 0
    for i in range(n):
        cnt = 0
        for j in range(n):
            if ch[i][j] == 1:
                cnt += 1
        res = max(res, cnt)
    print(res)
