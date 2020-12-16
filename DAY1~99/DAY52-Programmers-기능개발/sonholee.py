def solution(progresses, speeds):
    answer = []
    while True:
        if not progresses:
            break
        count = 0
        if progresses[0] >= 100:
            count += 1
            for i in range(1, len(progresses)):
                if progresses[i] >= 100:
                    count += 1
                else:
                    break
            for c in range(count):
                progresses.pop(0)
                speeds.pop(0)

            answer.append(count)
        for j in range(len(progresses)):
            progresses[j] += speeds[j]

    return answer
