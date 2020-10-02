n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr += [0]
cnt, s, e, target = 0, 0, 0, 0

while e <= n:
    if m < target:
        target -= arr[s]
        s += 1
    elif m > target:
        target += arr[e]
        e += 1
    else:
        target = target - arr[s]
        cnt += 1
        s += 1
print(cnt)

