def solution(n, c, g):
    ans = 0
    bucket = 0
    n_g = [[0]* (n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, n + 1):
            #1 태운거 내리기
            if bucket and n_g[j][i]:
                ans += n_g[j][i]
                bucket -= n_g[j][i]
            #2 태우기
        for j in range(1, n+1):
            room = c - bucket
            if room and g[i][j]:
                if room >= g[i][j]:
                    bucket += g[i][j]
                    n_g[i][j] = g[i][j]
                else:
                    bucket += room
                    n_g[i][j] = room
    return ans

if __name__ =='__main__':
    n, c = map(int, input().split())
    r = int(input())
    g = [[0] * (n+1) for _ in range(1+n)]
    for _ in range(r):
        a, b, x = map(int, input().split())
        g[a][b] = x
    print(solution(n, c, g))
    n, c, g = 4, 40, [[0, 0, 0, 0, 0], [0, 0, 10, 20, 30], [0, 0, 0, 10, 20], [0, 0, 0, 0, 20], [0, 0, 0, 0, 0]]

