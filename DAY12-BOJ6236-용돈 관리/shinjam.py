N, M = map(int, input().split())
K = [int(input()) for _ in range(N)]

left,right = 0,100_000
while left < right:
    mid = (left + right) // 2
    print(mid)
    tmp, cnt = 0, 1
    for d in K:
        tmp += d
        if tmp >= mid:
            cnt += 1
            tmp = d
            
    if cnt > M:
        left = mid + 1
    else:
        right = mid - 1
print(left)
