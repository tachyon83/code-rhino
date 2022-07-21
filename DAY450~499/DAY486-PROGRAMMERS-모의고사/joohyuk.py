def solution(answers):

    pAnswers = ['12345', '21232425', '3311224455']
    pIndex = [0, 0, 0]
    pPoints = [0, 0, 0]

    for i in range(len(answers)):
        for j in range(len(pIndex)):
            if answers[i] == int(pAnswers[j][pIndex[j]]):pPoints[j] += 1

            pIndex[j] += 1

            if pIndex[j] == len(pAnswers[j]):pIndex[j] = 0

    answer = []
    for i in range(len(pIndex)):
        if pPoints[i] == max(pPoints):answer.append(i+1)

    return answer
