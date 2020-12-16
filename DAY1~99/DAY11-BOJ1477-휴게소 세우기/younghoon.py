# 6 7 800
# 622 411 201 555 755 82
import sys
N, M, L = map(int, sys.stdin.readline().split())
rest_areas = list(map(int, sys.stdin.readline().split()))
rest_areas.sort()
rest_areas.append(L)
# print(rest_areas)

prev = 0
dists = list()

for rest_area in rest_areas:
    dists.append(rest_area - prev)
    prev = rest_area

# print(dists)
    
def build_areas(divide):
    global dists
    count = 0
    for dist in dists:
        count += dist // divide
        if dist % divide == 0:
            count -= 1
    return count
    
l,r = 1,1000
while l<=r:
    m = (l+r)//2
    # print(l,m,r)
    if build_areas(m) <= M:
        result = m
        r = m-1
    else:
        l = m+1
print(result)
