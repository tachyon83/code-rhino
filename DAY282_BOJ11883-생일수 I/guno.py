import sys
input=sys.stdin.readline

T=int(input())
nums=[int(input()) for _ in range(T)]

INF=max(nums)
dp=[(0,0,0,0)]+[(INF,INF,INF,INF)]*(INF+1)

for i in range(1,INF+1):
    left3=(dp[i-3][0]+1,dp[i-3][1]+1,dp[i-3][2],dp[i-3][3])
    left5=(dp[i-5][0]+1,dp[i-5][1],dp[i-5][2]+1,dp[i-5][3])
    left8=(dp[i-8][0]+1,dp[i-8][1],dp[i-8][2],dp[i-8][3]+1)
    dp[i]=min(left3,left5,left8,key=lambda x:(x[0],-x[1],-x[2],-x[3]))

for num in nums:
    q,a,b,c=dp[num]
    if a>=INF:
        print(-1)
    else:
        print(''.join(['3' for _ in range(a)])+''.join(['5' for __ in range(b)])+''.join(['8' for __ in range(c)]))


##찾은 풀이
T = int(input())
q = [1,2,4,7]
w = [9,10,12,15,20]
e = [6,9,12]
while T:
    T-=1
    n = int(input())
    if n in q:
        print(-1)
    else:
        a = b = c = 0
        while n >= 8:
            if n in w:
                break
            n -= 8
            c += 1
        while n >= 5:
            if n in e:
                break
            b += 1
            n -= 5
        a = n // 3
        print('3'*a+'5'*b+'8'*c)
