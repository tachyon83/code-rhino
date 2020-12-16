import sys

input = sys.stdin.readline

n, k = map(int, input().split())
coin  = []
coin_cnt = 0

for i in range(n) :
  coin.append(int(input()))

while k > 0 :
  for c in coin[::-1] :
    coin_cnt += k // c
    k %= c

print(coin_cnt)
