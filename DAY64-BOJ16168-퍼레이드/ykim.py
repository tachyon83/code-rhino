from collections import deque
v,e=map(int,input().split())
link=[list() for i in range(v+1)]
visit=[False]*(v+1)
for i in range(e):
    a,b=map(int,input().split())
    link[a].append(b)
    link[b].append(a)
Q=deque()
Q.append(1)
visit[1]=True
while Q:
    i=Q.popleft()
    for j in link[i]:
        if not visit[j]:
            Q.append(j)
            visit[j]=True
if False in visit[1:]:
    print('NO')
    exit()
c=0
for i in link:
    if len(i)%2: c+=1
if c==0 or c==2:
    print('YES')
else:
    print('NO')
