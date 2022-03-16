def solution(n, times):
    left, right = 1, max(times) * n
    answer = 0
    
    while left <= right :
        mid = (left + right) // 2
        temp = n
        for i in times :
            temp -= mid // i
            if temp <= 0 :
                answer = mid
                right = mid - 1
                break

        if temp > 0 :
            left = mid + 1
    return answer
