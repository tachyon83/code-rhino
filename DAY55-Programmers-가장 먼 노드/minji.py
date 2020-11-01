from collections import deque

def solution(n, edge):
    route = dict()
    for n1, n2 in edge:
        route.setdefault(n1, []).append(n2)
        route.setdefault(n2, []).append(n1)
    q = deque([[1, 0]])
    cnt = [-1]*(n+1)
    while q:
        i, d = q.popleft()
        cnt[i] = d
        for j in route[i]:
            if cnt[j] == -1:
                cnt[j] = 0
                q.append([j, d+1])
    return cnt.count(max(cnt))
