def solution(n, m, dic):
    import heapq
    visited = [0] * (n+1)

    keys = [[9999999999999, i] for i in range(n+1)]
    keys[1][0] = 0
    keys[0][0] = 0

    hq = []
    
    heapq.heappush(hq,keys[1])
    while hq:
        c, node = heapq.heappop(hq)
        if visited[node]:
            continue
        visited[node] = 1
        
        for v, cost in dic[node]:
            if not visited[v] and cost < keys[v][0]:
                keys[v][0] = cost
                heapq.heappush(hq, tuple(keys[v]))
    res = 0
    max_value = 0
    for key in keys:
        cost, _ = key
        res += cost
        max_value = max(max_value, cost)
    return res - max_value


if __name__ == "__main__":
    n,m = map(int, input().split())
    dic = {}
    for _ in range(m):
        a, b, c = map(int, input().split())
        if dic.get(a) is None:
            dic[a] = [(b, c)]
        else:
            dic[a].append((b,c))
        if dic.get(b) is None:
            dic[b] = [(a, c)]
        else:
            dic[b].append((a, c))
    # dic = {1: [(2, 3), (3, 2), (5, 5), (6, 2)], 2: [(1, 3), (3, 1), (5, 2)], 3: [(1, 2), (2, 1), (4, 4), (7, 6)], 5: [(2, 2), (1, 5), (6, 3), (4, 3)], 4: [(3, 4), (6, 1), (5, 3)], 7: [(3, 6), (6, 4)], 6: [(1, 2), (4, 1), (5, 3), (7, 4)]}
    # n,m= 7, 12

    print(solution(n, m, dic))
