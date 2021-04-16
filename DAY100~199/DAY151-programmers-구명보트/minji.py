def solution(people, limit):
    answer = len(people)
    sp = sorted(people)
    s, e = 0, len(people) - 1
    while s < e:
        if sp[s] + sp[e] <= limit:
            answer -= 1
            s += 1
        e -= 1
    return answer
