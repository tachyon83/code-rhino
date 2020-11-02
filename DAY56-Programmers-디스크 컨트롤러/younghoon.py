def solution(jobs):
    result = 0
    time = 0
    length = len(jobs)
    jobs = sorted(jobs, key=lambda x: x[1])  # 소요시간 우선 정렬
    while jobs:
        for i in range(len(jobs)):
            if jobs[i][0] <= time:
                time += jobs[i][1]
                result += time - jobs[i][0]
                jobs.pop(i)
                break
            if i == len(jobs)-1:
                time += 1
    return result // length
