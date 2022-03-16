def solution(n, times):
    left = 0
    right = n * max(times)
    while left <= right:
        mid = (left + right)  // 2
        temp = 0
        for time in times:
            temp += mid // time
        
        if n <= temp:
            right = mid - 1
            answer = mid
        else:
            left = mid + 1
    return answer

if __name__ == "__main__":
    print(solution(6, [7, 10]))