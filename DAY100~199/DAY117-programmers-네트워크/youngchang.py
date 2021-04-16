def dfs(computers, i, visited):
    if visited[i]: return
    visited[i] = True
    for j in range(len(computers)):
        if computers[i][j]:
            dfs(computers, j, visited)
            
def solution(n, computers):
    answer = 0
    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            answer += 1
            dfs(computers, i, visited)
    return answer