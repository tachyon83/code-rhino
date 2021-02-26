def solution(operations):
    answer = []
    for i in operations:
        a, b = i.split(" ")
        if a == "I":
            answer.append(int(b))
        else:
            if len(answer) > 0:
                if b == "1":
                    answer.pop()
                else:
                    answer.pop(0)
            else:
                pass
        answer.sort()
    if len(answer) == 0:
        return [0, 0]
    else:
        return [max(answer), min(answer)]
    return answer
