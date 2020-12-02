from collections import Counter

def solution(N, stages):
    result = {}
    given = len(stages)
    counter = Counter(stages)
    for stage in range(1, N+1):
        if given:
            result[stage] = counter[stage] / given
            given -= counter[stage]
        else:
            result[stage] = 0
    return sorted(result, key=lambda x : result[x], reverse=True)
