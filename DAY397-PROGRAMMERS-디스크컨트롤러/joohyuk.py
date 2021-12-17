import heapq


def solution(jobs):
    n, jobs, currTime, pq, t, pos, hold = len(jobs), sorted(jobs), 0, [], 0, 0, 0

    while pos < n:
        if jobs[pos][0] <= currTime:
            heapq.heappush(pq, jobs[pos][::-1])
            pos += 1
        elif not pq:
            currTime = jobs[pos][0]
            heapq.heappush(pq, jobs[pos][::-1])
            pos += 1
        else:
            curr = heapq.heappop(pq)
            t += curr[0]+currTime-curr[1]
            currTime += curr[0]

    while pq:
        curr = heapq.heappop(pq)
        t += curr[0]+currTime-curr[1]
        currTime += curr[0]

    return t//n
