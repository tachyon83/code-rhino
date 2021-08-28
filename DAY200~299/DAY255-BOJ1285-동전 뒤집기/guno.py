import sys
input=sys.stdin.readline

n,answer=int(input()),10000
coins=[input() for _ in range(n)]
coins=list(map(lambda coin:sum(1<<(n-i-1)
    for i in range(n) if coin[i]=='T'),coins))

for r in range(1<<n):
    now_sum=0

    for i in range(n):
        temp=bin(coins[i]^r).count('1')
        now_sum+=min(temp,n-temp)
    answer=min(answer,now_sum)

print(answer)

# 뒤집을 열 조합을 정해놓은 후 
# 각 행마다 최소 T개수 찾기
# 이 과정 모든 열 조합에서 반복
