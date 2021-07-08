import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
v=[[] for _ in range(n+1)]
sccs=[]
d=[0]*(n+1)
finished=[False]*(n+1)
i=0
st=[]
def dfs(x):
    global i
    i+=1
    d[x]=i
    st.append(x)
    parent=d[x]
    for y in v[x]:
        if d[y]==0:
            parent=min(parent,dfs(y))
        elif not finished[y]:
            parent=min(parent,d[y])
    if parent==d[x]:
        temp=[]
        while True:
            s=st.pop()
            temp.append(s)
            finished[s]=True
            if s==x:
                break
        sccs.append(temp)
    return parent

    
for _ in range(m):
    a,b=map(int,input().split())
    v[b].append(a)

for j in range(1,n+1):
    if d[j]==0:
        dfs(j)

print(sccs)
