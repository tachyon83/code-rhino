'''
이해못했습니당 ㅠ
dp공부를 더하고 봐야겠어요
'''

import sys
sys.setrecursionlimit(10**9)
 
N=int(sys.stdin.readline())
Tree=[[] for _ in range(N+1)]
check=[0 for _ in range(N+1)]
for _ in range(N-1):
    u,v=map(int,sys.stdin.readline().split())
    Tree[u].append(v)
    Tree[v].append(u)
DP=[[0,0] for _ in range(N+1)]
 
check=[True for _ in range(N+1)]
def DFS(cur):
    check[cur]=False
    DP[cur][0]=1
    DP[cur][1]=0
    for i in Tree[cur]:
        if check[i]:
            DFS(i)
            DP[cur][0]+=DP[i][1]
            DP[cur][1]+=max(DP[i][0],DP[i][1])
 
DFS(1)
print(N-max(DP[1][0],DP[1][1]))
