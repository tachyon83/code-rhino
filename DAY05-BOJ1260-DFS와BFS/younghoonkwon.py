import sys

N, M, start = map(int, sys.stdin.readline().split(' '))

adj_matrix = list([0] * (N + 1) for _ in range(N+1))

for i in range(M):
    a, b = map(int, sys.stdin.readline().split(' '))
    adj_matrix[a][b] = 1
    adj_matrix[b][a] = 1

visited = list([0] * (N + 1))

def dfs(start):
    print(start, end = ' ')
    visited[start] = 1
    for i in range(1, N + 1):
        if visited[i] == 0 and adj_matrix[start][i] == 1 :
            dfs(i)
            
dfs(start)
print()
visited = list([0] * (N + 1))

def bfs(start):
    queue = [start]
    visited[start] = 1
    while queue:
        curr = queue.pop(0)
        print(curr, end = ' ')
        for i in range(1, N + 1):
            if adj_matrix[curr][i] == 1 and visited[i] == 0:
                queue.append(i)
                visited[i] = 1
bfs(start)


            
    
