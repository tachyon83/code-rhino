
def solution(n, times):
    l, r = 1, min(times)*n
    ans = 0
    while l <= r:
        mid = (l+r)//2
        if sum(map(lambda x: mid//x, times)) >= n:
            ans = mid
            r = mid-1
        else:
            l = mid + 1
    
    return ans
