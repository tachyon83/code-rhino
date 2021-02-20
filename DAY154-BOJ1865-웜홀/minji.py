import sys
INF = int(1e9)

def bf(dist, edges, n):
    dist[1] = 0
    for i in range(n):
        for j in range(1, n+1):
            for nv, nw in edges[j]:
                if dist[nv] > dist[j] + nw:
                    dist[nv] = dist[j] + nw
                    if i == n-1:
                        return "YES"
    return "NO"

if __name__ == "__main__":
    tc = int(sys.stdin.readline())

    for _ in range(tc):
        n, m, w = map(int, sys.stdin.readline().split())
        dist = [INF] * (n+1)
        edges = [[] for _ in range(n+1)]

        for _ in range(m):
            s, e, t = map(int, sys.stdin.readline().split())
            edges[s].append([e, t])
            edges[e].append([s, t])

        for _ in range(w):
            s, e, t = map(int, sys.stdin.readline().split())
            edges[s].append([e, -t])

        print(bf(dist, edges, n))
