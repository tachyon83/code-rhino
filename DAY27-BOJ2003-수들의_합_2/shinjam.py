N, M = map(int, input().split())
ARR = list(map(int, input().split()))
ans = 0
cur_sum = ARR[0]
i, j = 0, 1
while i <= j:
    if cur_sum == M:
        ans += 1
    if cur_sum < M and j < N:
        cur_sum += ARR[j]
        j += 1
    elif cur_sum >= M and i < N:
        cur_sum -= ARR[i]
        i += 1
    else:
        break
    
print(ans)
