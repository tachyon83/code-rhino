# 모든 숫자는 가로 조각 또는 세로 조각의 원소
# 한 줄에서는  이어진 조각이 분리된 조각보다 무조건 크거나 같음
# ex) (1,1,1) 보다는 (3)이 더 큼
# 비트마스크 이용해 조각  표현, 브루트포스

import sys
input=sys.stdin.readline

n,m=map(int,input().split())
paper=[[int(i) for i in input().rstrip()] for _ in range(n)]
result=0

for b in range((1<<n*m)):
    visited=[[False for _ in range(m)] for __ in range(n)]
    horizon=[[False for _ in range(m)] for __ in range(n)]
    now_sum=0
    for i in range(n*m):
        if (1<<i)&b:
            horizon[i//m][i%m]=True
    for y in range(n):
        for x in range(m):
            if visited[y][x]:continue

            temp=paper[y][x]
            visited[y][x]=True
            i=1
            if horizon[y][x]:#가로상자 원소일때
                while x+i<m and horizon[y][x+i]:
                    temp=temp*10+paper[y][x+i]
                    visited[y][x+i]=True
                    i+=1
            else:
                while y+i<n and not horizon[y+i][x]:
                    temp=temp*10+paper[y+i][x]
                    visited[y+i][x]=True
                    i+=1
            now_sum+=temp
    result=max(result,now_sum)

print(result)
