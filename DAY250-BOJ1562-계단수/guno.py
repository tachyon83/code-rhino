import sys
input=sys.stdin.readline

n=int(input())
dp=[[0]*1024 for _ in range(10)]

for i in range(1,10):
    dp[i][1<<i]=1

for _ in range(1,n):
    dp_next=[[0]*1024 for _ in range(10)]
    for i in range(10):
        for bit in range(1024):
            if i<9:
                dp_next[i][bit|(1<<i)]+=dp[i+1][bit]
            if i>0:
                dp_next[i][bit|(1<<i)]+=dp[i-1][bit]
            dp_next[i][bit|(1<<i)]%=1000000000
    dp=dp_next

print(sum([dp[i][1023] for i in range(10)])%1000000000)
