import sys
from collections import deque
input=sys.stdin.readline

n,k=map(int,input().split())

if n>=k:
    print(n-k)
else:
    visited=[False]*100001
    q=deque()
    q.append((n,0))
    visited[n]=True

    def visit(a,cnt):
        if a==k:
            print(cnt+1)
            return True
        if 0<=a<=100000 and not visited[a]:
            visited[a]=True
            q.append((a,cnt+1))
        return False

    while q:
        a,cnt=q.popleft()
        if visit(a-1,cnt) or visit(a+1,cnt) or visit(a*2,cnt):
            break
