import sys
si = sys.stdin.readline

n, k = [int(e) for e in si().split()]
coinList = []
for _ in range(n):
    coinList.append(int(si()))
coinList = coinList[::-1]
count = 0


def solve(balance, l):
    global count
    for idx, coin in enumerate(l):
        if coin <= balance:
            count += balance//coin
            balance -= coin*(balance//coin)
            try:
                solve(balance, l[idx+1:])
            except:
                return
            return


solve(k, coinList)
print(count)
