N = int(input())
sltn = sorted([int(x) for x in input().split(' ')])

l, r = 0, N - 1
result = sltn[l] + sltn[r]
rl = l
rr = r
while l < r:
    tmp = sltn[l] + sltn[r]
    if abs(tmp) < abs(result):
        result = tmp
        rl = l
        rr = r
    if tmp < 0:
        l += 1
    else:
        r -= 1
        
print(sltn[rl], sltn[rr])
