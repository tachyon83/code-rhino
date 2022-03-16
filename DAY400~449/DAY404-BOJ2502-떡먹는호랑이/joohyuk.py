import sys
si=sys.stdin.readline

d,k=[int(e) for e in si().split()]
dp=[0 for _ in range(d+1)]
dp[d]=k

def f(day,v):
    dp[day]=v
    if day==1:return True
    if dp[day+1]-v>=v:return False
    return f(day-1,dp[day+1]-v)

start=k//2+1
for i in range(start,k):
    if f(d-1,i):break
print(dp[1])
print(dp[2])
