def solution(brown, yellow):
    temp = (brown-4)//2
    for e in range(1, temp):
        y = e*(temp-e)
        if (e+2)*(temp-e+2)-y == brown and y == yellow and e+2>=(temp-e+2):
            answer = [e+2, temp-e+2]
            break
    return answer
