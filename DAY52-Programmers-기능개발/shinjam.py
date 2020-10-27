import math

def solution(progresses, speeds):
    ans = [0]
    cost = []
    for p, s in zip(progresses, speeds):
        cost.append(math.ceil((100-p)/s))
    pivot = cost[0]
    for c in cost:
        if c <= pivot:
            ans[-1] += 1
        else:
            ans.append(1)
            pivot = c

    return ans
