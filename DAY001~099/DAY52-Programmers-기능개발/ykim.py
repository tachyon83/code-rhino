import math 
def solution(progresses, speeds):
    answer = []
    check = [ math.ceil((100 - x)/y) for x, y in zip(progresses, speeds)]
    while len(check) > 0:

        # 자기 자신 포함 
        cnt = 1
        a = check.pop(0)
        check1 = check.copy()
        for i in range(len(check)):
            if a >= check[i]:
                cnt += 1
                # 계산한 내역은 빼줘야 함 
                check1.pop(0)
            else:
                break
        answer.append(cnt)
        check = check1.copy()

    return answer
