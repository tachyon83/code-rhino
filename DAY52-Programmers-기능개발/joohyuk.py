def solution(progresses, speeds):
    curr, answer, n = 0, [], len(speeds)
    while curr < n:
        if progresses[curr] < 100:
            d = 0
            if (100-progresses[curr]) % speeds[curr]:
                d = 1
            d += (100-progresses[curr])//speeds[curr]

            for i in range(curr, n):
                progresses[i] += d*speeds[i]

        cnt = 0
        while curr < n and progresses[curr] >= 100:
            cnt += 1
            curr += 1
        answer.append(cnt)

    return answer
