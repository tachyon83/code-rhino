def solution(n, times):
    ans = 0

    left = 1
    right = n * max(times)

    while left <= right:
        mid = (left + right) // 2
        cnt = 0
        for time in times:
            cnt += mid // time
            if cnt >= n:
                ans = mid
                right = mid - 1
                break

        if cnt < n:
            left = mid + 1

    return ans
