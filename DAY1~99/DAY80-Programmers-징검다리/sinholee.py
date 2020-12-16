def solution(distance, rocks, n):
    rocks.sort()
    left = 0
    right = distance

    # 많은분들이 마지막 distance를 추가하지 않아서 반례테케가 있는데 통과되는것 같습니다.
    rocks.append(distance)
    answer = 0
    while left <= right:
        mid = (left+right)//2
        curr_point = 0 
        cnt = 0
        for rock in rocks:
            if rock-curr_point < mid:
                cnt += 1
            else:
                curr_point = rock
        # print(mid, cnt)
            
        if n < cnt:
            right = mid - 1
        else:
            answer = mid
            left = mid + 1
    return answer
        
        
if __name__ == "__main__":
    #반례가 되는 테케들
    print(solution(10, [6,7,8,9], 3))
    print(solution(5,[1,2,3,4],2))