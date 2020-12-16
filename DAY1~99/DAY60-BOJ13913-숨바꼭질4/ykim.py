from collections import deque

def solve(visited,n,k):
    queue=deque()
    queue.append(n)
    while queue:
        x=queue.popleft()

        if x==k:
            #이동하는데 걸리는 최소시간
            print(visited[x])
            #이동한방법은 이동경로를 역순으로 출력
            p=[]
            #p에다가 마지막경로인 x를 넣고
            #x에다가 다시 path에 저장해둔 이전의 좌표 넣기
            #x가 시작점과 같아질때까지 반복
            while x!=n:
                p.append(x)
                x=path[x]
            #while문이 n일때 나가니깐 n은 추가해주기
            p.append(n)
            p.reverse()
            print(' '.join(map(str,p)))
            return

        for nx in (x+1,x-1,x*2):
            if 0<=nx<100001 and visited[nx]==0:
                visited[nx]=visited[x]+1
                #path[다음좌표]=현재좌표
                path[nx]=x
                queue.append(nx)

n,k=map(int,input().split())
visited=[0]*100001
path=[0]*100001
solve(visited,n,k)
