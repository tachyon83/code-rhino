def solution(distance, rocks, n):
    rocks.sort()
    l, r = 0, distance
    ans = 0
    while l <= r:
        mid = (l+r)//2
        cur, cnt = 0, 0
        for rock in rocks:
            if rock-cur < mid:
                cnt += 1
            else:
                cur = rock
            
        if cnt <= n:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    return ans
        
        
