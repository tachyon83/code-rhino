N, M = map(int, input().split())
costs = [int(input()) for _ in range(N)]

low, high = max(costs), sum(costs)
while low < high:
    cnt, k = 0, 0
    mid = (low + high) // 2
    for cost in costs:
        if k < cost:
            k = mid
            cnt += 1
        k -= cost
    if cnt > M:
        low = mid + 1
    else:
        high = mid - 1
print(low)
