import sys
bars = [0] * 1001
for _ in range(int(sys.stdin.readline())):
    L, H = map(int, sys.stdin.readline().split())
    bars[L] = H
    
ans = 0
l, r = 0, 1000
l_top, r_top = 0, 0
while l<=r:
    if bars[l]<=bars[r]:
        if bars[l] > l_top:
            l_top = bars[l]
        ans += l_top
        l += 1
    else:
        if bars[r] > r_top:
            r_top = bars[r]
        ans += r_top
        r -= 1
print(ans)
