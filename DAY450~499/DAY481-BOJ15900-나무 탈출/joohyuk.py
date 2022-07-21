import sys
si = sys.stdin.readline
sys.setrecursionlimit(500000+1)

n=int(si())
g=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=[int(e) for e in si().split()]
    g[a].append(b)
    g[b].append(a)

cnt=0
def count(i,prv):
    global cnt
    if i!=1 and len(g[i])==1:cnt+=1
    for nx in g[i]:
        if nx==prv:continue
        count(nx,i)

count(1,0)
print('Yes' if cnt%2 else 'No')

