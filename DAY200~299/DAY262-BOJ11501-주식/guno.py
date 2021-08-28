import sys
input = sys.stdin.readline

T=int(input())
for _ in range(T):
    n=int(input())
    prices=list(map(int,input().split()))
    _max,result=prices[-1],0
    for price in reversed(prices):
        if _max<price:
            _max=price
        else:
            result+=_max-price

    print(result)
