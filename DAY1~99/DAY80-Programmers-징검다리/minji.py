def solution(distance, rocks, n):
    rocks.sort()
    left, right = 0, distance
    ans = 0
    while left <= right:
        mid = (left+right)//2
        cur, remove_cnt = 0, 0
        for rock in rocks:
            if rock-cur < mid:
                remove_cnt += 1
            else:
                cur = rock
            
        if remove_cnt <= n:
            ans = mid
            left = mid + 1
        else:
            right = mid - 1
    return ans
