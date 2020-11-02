import heapq

# [(현재+작업시간-시작시간, 시작, 작업시간)]

def solution(jobs):
    jobs.sort()
    total = 0
    now = 0
    n = len(jobs)
    hq = []
    for i in range(n):
        started_at, work = jobs[i]
        while started_at >= now and hq:
            w, s = heapq.heappop(hq)
            if s < now:
                now += w
            else:
                now = s + w
            total += now - s
        else:
            heapq.heappush(hq, (work, started_at))
    while hq:
            work, started_at = heapq.heappop(hq)
            if started_at < now:
                now += work
            else:
                now = started_at + work
            total += now - started_at


    return total // n
