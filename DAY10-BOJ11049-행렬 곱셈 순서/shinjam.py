N = int(input())
matrix = [[*map(int, input().split())] for _ in range(N)]
dp = [[0] * N for _ in range(N)] 

for i in range(1, N): # 행
    for j in range(0, N-i): # 열
        if i == 1: # 단일 곱셈
            dp[j][j + i] = matrix[j][0] * matrix[j][1] * matrix[j + i][1]
            continue
        cand = [
            dp[j][k] + dp[k+1][j+i] + matrix[j][0] * matrix[k][1] * matrix[j+i][1]
            for k in range(j, j+i)
        ]
        dp[j][j+i] = min(cand)
                
print(dp[0][N-1]) # 정답
