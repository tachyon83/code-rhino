'''
저도 반례못찾겠네요ㅠ
'''
def draw(square, mat):
    x1, y1, x2, y2 = square
    x1 += 1000 + x1
    y1 += 1000 + y1
    x2 += 1000 + x2
    y2 += 1000 + y2
    added_cnt = -4
    for x in  range(x1, x2+2):
        mat[y1][x] = 1
        mat[y2][x] = 1
        added_cnt +=2

    for y in  range(y1, y2+2):
        mat[y][x1] = 1
        mat[y][x2] = 1
        added_cnt+=2
    return mat, added_cnt

def bfs(y, x, mat, visited):
    dy = [0, 1, 0, -1]
    dx = [1, 0, -1, 0]
    q = [(y, x)]
    cnt = 1
    visited[y][x] = 1
    while q:
        y, x = q.pop(0)
        for k in range(4):
            ny, nx = y+dy[k], x+dx[k]
            if not (0<=ny<2003 and 0<=nx<2003):
                continue
            if visited[ny][nx]:
                continue
            if mat[ny][nx]:
                q.append((ny, nx))
                visited[ny][nx] = 1
                cnt += 1
    return visited, cnt
def solution(n, squares):
    visited = [[0] * 2003 for _ in range(2003)]
    mat = [[0] * 2003 for _ in range(2003)]
    total_cnt = 0
    for square in squares:
        mat, added_cnt = draw(square, mat)
        total_cnt += added_cnt
    if mat[1000][1000]:
        res = 0
    else:
        res = 1
    # total_cnt = sum(sum(mat,[]))
    for i in range(2003):
        for j in range(2003):
            if not visited[i][j] and mat[i][j]:
                visited, cnt = bfs(i,j,mat,visited)
                total_cnt -= cnt
                if total_cnt:
                    res += 1
    return res
if __name__ == "__main__":
    n = int(input())
    squares = [[*map(int, input().split())] for _ in range(n)]
    print(solution(n, squares))
