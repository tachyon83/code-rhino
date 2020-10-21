def solution(n, mat):
    res = 99999999999999999999
    dy = [0, 0, 1, 0, -1]
    dx = [0, 1, 0, -1, 0]
    for a in range(n**2):
        for b in range(a+1, n**2):
            for c in range(b+1, n**2):
                visited = [[0] * n for _ in range(n)]
                ay, ax = a // n , a % n
                by, bx = b // n , b % n
                cy, cx = c // n , c % n
                flag = True
                temp = 0
                for k in range(5):
                    nay, nax = ay+dy[k], ax+dx[k]
                    if not (0<=nay<n and 0<=nax<n) or visited[nay][nax]:
                        flag = False
                        break
                    else:
                        visited[nay][nax] = 1
                        temp += mat[nay][nax]
                    nby, nbx = by+dy[k], bx+dx[k]
                    if not (0<=nby<n and 0<=nbx<n) or visited[nby][nbx]:
                        flag = False
                        break
                    else:
                        visited[nby][nbx] = 1
                        temp += mat[nby][nbx]
                    ncy, ncx = cy+dy[k], cx+dx[k]
                    if not (0<=ncy<n and 0<=ncx<n) or visited[ncy][ncx] :
                        flag = False
                        break
                    else:
                        visited[ncy][ncx] = 1
                        temp += mat[ncy][ncx]
                if flag:
                    res = min(res, temp)
    return res


if __name__ == "__main__":
    n = int(input())
    mat = [[*map(int, input().split())] for _ in range(n)]
    print(solution(n, mat))
    
