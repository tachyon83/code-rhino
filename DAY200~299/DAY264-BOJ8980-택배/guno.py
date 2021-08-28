import sys
from collections import deque
input=sys.stdin.readline

n,c=map(int,input().split())
m=int(input())
limit=[c]*(n+1)#i번째 마을에서 실을수 있는 상자 개수
infos=[list(map(int,input().split())) for _ in range(m)]
infos.sort(key=lambda x:(x[1],x[0]))#도착지 기준으로 정렬

answer=0
for a,b,box in infos:
    box_up_limit=min(limit[a:b]+[box])
    answer+=box_up_limit
    for i in range(a,b):
        limit[i]-=box_up_limit

print(answer)
