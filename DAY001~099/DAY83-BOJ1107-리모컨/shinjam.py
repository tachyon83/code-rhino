N = int(input())
M = int(input())

possible = set(range(10)) - set(map(int, input().split()))

ans = abs(100 - N)


for num in range(5500):
    check = set(map(int, str(num)))
    if not (check - possible):
        ans = min(ans, abs(N-num)+len(str(num)))

print(ans)
