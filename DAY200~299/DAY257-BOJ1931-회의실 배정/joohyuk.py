import sys
si=sys.stdin.readline

n=int(si())
time,arr,cnt=0,[],0
for _ in range(n):
    s,t=[int(e) for e in si().split()]
    arr.append([t,s])
arr.sort()

for p in arr:
    t,s=p
    if s>=time:
        cnt+=1
        time=t
print(cnt)
