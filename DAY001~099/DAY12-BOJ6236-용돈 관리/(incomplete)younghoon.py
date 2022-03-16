import sys
N, M = map(int, sys.stdin.readline().split())
moneys = []
for _ in range (N):
    moneys.append(int(input()))


def count_withdrawals(withdrawal):
    global N,M,moneys
    leftover = withdrawal
    count = 1
    for i in range(N):
        if moneys[i] <= leftover:
            leftover = leftover - moneys[i]
        else:
            leftover = withdrawal
            count += 1
            leftover = leftover - moneys[i]
    return count

l, r = 1, sum(moneys)
result = 0
while l <= r:
    m = (l+r)//2
    print(l,m ,r)
    if count_withdrawals(m) <= M :
        result = m 
        r = m - 1
    else :
        l = m + 1
print(result)
            
