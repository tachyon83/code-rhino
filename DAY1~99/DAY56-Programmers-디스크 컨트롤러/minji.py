def solution(jobs):
    answer, start, length = 0, 0, len(jobs)
    jobs = sorted(jobs, key=lambda x: x[1])

    while len(jobs) != 0:
        for i in range(len(jobs)):
            if jobs[i][0] <= start:
                start += jobs[i][1]
                answer += start - jobs[i][0]
                jobs.pop(i)
                break
            if i == len(jobs) - 1:
                start += 1

    return answer // length
