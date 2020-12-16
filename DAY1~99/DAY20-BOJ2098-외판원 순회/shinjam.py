from collections import defaultdict
from math import inf

class Node:
    def __init__(self):
        self.dp = defaultdict(lambda:inf)

N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]
nd = {i:Node() for i in range(N)}

def dfs():
    stack = [(0, 0, [0])] # 정점, 비용, 경로
    ret = inf
    while stack:
        cur, cur_w, r = stack.pop()
        
        if len(r) == N:
            if W[cur][0] != 0 and cur_w + W[cur][0] < ret:
                ret = cur_w + W[cur][0]
            continue
        
        for i in range(N):
            new_r, new_w = [*r, i], cur_w + W[cur][i]

            if not W[cur][i] or i in r: # 없는 경로, 이미 들른 경로
                continue
            if nd[i].dp[len(new_r)] < new_w:
                continue
            nd[i].dp[len(new_r)] = new_w
            stack.append((i, new_w, new_r))
            
    return ret if ret != inf else 0

print(dfs())
