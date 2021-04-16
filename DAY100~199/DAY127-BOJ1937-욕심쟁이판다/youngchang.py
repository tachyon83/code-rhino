import sys
sys.setrecursionlimit(10 ** 8)

def solution(N, board):
    answer = 0
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]
    is_in = lambda r, c: 0 <= r < N and 0 <= c < N
    dp = [[0] * N for _ in range(N)]
    
    def move(r, c):
        if dp[r][c] != 0: return dp[r][c]
        res = 1
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]
            if is_in(nr, nc) and board[r][c] < board[nr][nc]:
                res = max(res, move(nr, nc) + 1)
        dp[r][c] = res
        return res
        
    for i in range(N):
        for j in range(N):
            answer = max(answer, move(i, j))
    
    return answer

def read_in():
    for line in sys.stdin:
        yield line.replace('\n', '')
        
def main():
    reader = read_in()
    N = int(next(reader))
    board = []
    for _ in range(N):
        row = list(map(int, next(reader).split()))
        board.append(row)
    
    answer = solution(N, board)
    print(answer)
    
main()