def solution(dartResult):
    i, sz = 0, len(dartResult)
    scores = [0 for _ in range(3)]
    powerMap = {'S': 1, 'D': 2, 'T': 3}
    nums = '0123456789'

    score, k = '', 0
    while i < sz:
        if dartResult[i] in nums:
            score += dartResult[i]
        elif dartResult[i] not in nums:
            scores[k] = int(score)
            score = ''
            scores[k] **= powerMap[dartResult[i]]

            if i+1 < sz and dartResult[i+1] not in nums:
                if dartResult[i+1] == '*':
                    scores[k] *= 2
                    if k > 0:
                        scores[k-1] *= 2
                else:
                    scores[k] *= -1
                i += 1
            k += 1
        i += 1

    return sum(scores)
