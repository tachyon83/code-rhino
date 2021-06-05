import sys
input=sys.stdin.readline
n=int(input())
meetings=[list(map(int,input().split())) for _ in range(n)]
meetings.sort(key=lambda x:(x[1],x[0]))
now,answer=0,0
for meeting in meetings:
    if now<=meeting[0]:
        answer+=1
        now=meeting[1]
print(answer)
