from collections import defaultdict
def solution(n, edge):
    data2node = defaultdict(list)
    visited = [False] * (n+1)
    for e in edge:
        data2node[e[0]].append(e[1])
        data2node[e[1]].append(e[0])
    q = []
    q.append(1)
    visited[1] = True
    result = 0
    while q:
        adj_list = []
        result = len(q)
        while q:
            curr = q.pop(0)    
            adj_list.extend(data2node[curr])
        for adj in adj_list:
            if visited[adj] == False:
                visited[adj] = True
                q.append(adj)
    return result
