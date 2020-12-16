import sys

N = int(sys.stdin.readline())

adj_matrix = list([0] * (N + 1) for _ in range(N+1))
visited = list([0] * (N + 1))

def init():
    while True:
        a, b = map(int, sys.stdin.readline().split(' '))
        if a == -1 and b == -1:
            break
        adj_matrix[a][b] = 1
        adj_matrix[b][a] = 1


def bfs(v):
    queue = [v]
    visited[v] = 1
    depth = 0
    while queue:
        for _ in range(len(queue)):
            curr = queue.pop(0)
            # print(curr, end = ' ')
            for i in range(1, N + 1):
                if adj_matrix[curr][i] == 1 and visited[i] == 0:
                    queue.append(i)
                    visited[i] = 1
        if queue:
            depth += 1
    return depth

def election():
    global visited
    depth_list = []
    elected = []
    for i in range(1, N+1):
        # reset visited
        visited = list([0] * (N + 1))
        depth_list.append(bfs(i))
    score = min(depth_list)
    for i in range(len(depth_list)):
        if depth_list[i] == score:
            elected.append(i+1)
    print(score, len(elected))
    print(*elected)

init()
election()



            
    
