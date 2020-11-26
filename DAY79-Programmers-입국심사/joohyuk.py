def solution(n, times):
    s, e = 1, max(times)*n

    while s < e:
        cnt = 0
        mid = (s+e)//2
        for time in times:
            cnt += mid//time
        if cnt < n:
            s = mid+1
        else:
            e =mid
    return (s+e)//2

