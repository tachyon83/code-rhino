def solution():
    n, m= map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(n)]
    curr_cheese_cnt = sum(sum(mat, []))
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    
    def check_border(del_cheese_cnt, visited):
        '''
        가상자리에 있는 치즈의 개수를 세고,
        그 치즈들을 2로 표시하여 나중에 회차정보를 구하기 위해
        루프를 돌 때 치즈를 지우기 위해 visited를 반환한다.
        '''
        y, x = 0, 0
        visited[y][x] = 1
        q = [(y, x)]
        while q:
            y, x = q.pop(0)
            for k in range(4):
                ny, nx = y+dy[k], x+dx[k]
                if not (0 <= ny < n and 0 <= nx < m):
                    continue
                if visited[ny][nx]:
                    continue
                if mat[ny][nx]:
                    del_cheese_cnt += 1
                    visited[ny][nx] = 2
                else:
                    visited[ny][nx] = 1
                    q.append((ny, nx))
       
        return del_cheese_cnt, visited
    
    cnt = 0
    while True:
        del_cheese_cnt, visited = check_border(0, [[0] * m for _ in range(n)])
        cnt+=1
        # 현재 남아있는 치즈 개수와, 지워지는 치즈의 개수가 같으면
        # 라운드는 종료한다.
        if curr_cheese_cnt == del_cheese_cnt:
            print(cnt)
            print(del_cheese_cnt)
            return
        curr_cheese_cnt -= del_cheese_cnt
        # 치즈 없애기
        # visited[i][j] == 2는 가상자리의 치즈이므로 얘네만 지워서 
        # 루프를 돌린다.
        mat = [[0 if visited[i][j] == 2 else mat[i][j] for j in range(m)] for i in range(n)]
        
        
if __name__ == "__main__":
    solution()
