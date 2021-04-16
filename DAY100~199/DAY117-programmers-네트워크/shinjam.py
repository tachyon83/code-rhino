from collections import deque

def bfs(node):
    queue = deque([node])
    
    while queue:
        current = queue.popleft()
        visited[current] = 1
        for idx, val in enumerate(matrix):
            if val[current] and not visited[idx]:
                queue.append(idx)
    return 1
    
    
    

def solution(n, computers):
    global N, matrix, visited
    N, matrix = n, computers
    visited = [0] * N
    cnt = 0
    
    for node in range(N):
        if not visited[node]:
            cnt += bfs(node)
    return cnt
