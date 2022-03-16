N, M, L = map(int, input().split())
N_POS = [0, *sorted(map(int, input().split())), L]

left, right = 0, L
while left <= right:
    mid = (left + right) // 2
    n_cnt = 0
    for i in range(1, N + 2):
        dist = N_POS[i] - N_POS[i - 1]
        div, mod = divmod(dist, mid)
        n_cnt += div
        if mod == 0:
            n_cnt -= 1
        
    if n_cnt > M:
        left = mid + 1
    else:
        right = mid - 1
print(left)
