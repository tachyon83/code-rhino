from collections import Counter
def solution(N, stages):
    current = [0]*(N+2)
    for s in stages:
        current[s] += 1
    for i in range(N, -1, -1):
        current[i] += current[i+1]
    counter = Counter(stages)
    ans = []
    for i in range(1, N+1):
        ret = counter[i]/current[i] if current[i] else 0
        ans.append((i, ret))
    ans.sort(key=lambda x: -x[1])
    return next(zip(*ans))
