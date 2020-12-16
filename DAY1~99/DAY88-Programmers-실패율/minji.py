def solution(n, stages):
    answer = {}
    users = len(stages)
    for i in range(1, n+1):
        if users != 0:
            cnt = stages.count(i)
            answer[i] = cnt / users
            users -= cnt
        else:
            answer[i] = 0
    return sorted(answer, key=lambda x : answer[x], reverse=True)
