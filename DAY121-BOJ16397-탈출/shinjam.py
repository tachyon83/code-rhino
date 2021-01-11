from collections import deque

def bfs():
    queue = deque()
    queue.append(n)
    dist[n] = 0
    while queue:
        x = queue.popleft()
        if dist[x] > t:
            break
        if x == g:
            return dist[x]            
        dx = x+1, x*2
        for i in range(2):
            nx = dx[i]
            if nx > 99999:
                continue
            if i and x:
                nx -= 10**(len(str(nx))-1)
            if dist[nx] == -1:
                queue.append(nx)
                dist[nx] = dist[x]+1
    return "ANG"

n, t, g = map(int, input().split())
dist = [-1]*100000
bfs()

