import sys
input=sys.stdin.readline

dp=[[-1 for _ in range(101)] for _ in range(10001)]
T=int(input())
k=int(input())
coins=[]
for _ in range(k):
    coins.append(list(map(int,input().split())))

def dfs(money, num):
    if money==0:
        return 1
    if num>=k:
        return 0
    
    if dp[money][num]!=-1:
        return dp[money][num]
    
    result=0
    for i in range(coins[num][1]+1):
        coinMoney=coins[num][0]*i
        if money-coinMoney>=0:
            result+=dfs(money-coinMoney,num+1)
    dp[money][num]=result
    return dp[money][num]

print(dfs(T,0))