def solution(gems):
    howmany = len(set(gems))

    s, i, cnt, flag, hold = 0, 0, 100000, False, dict()
    while i < len(gems) or s < len(gems):
        if i >= len(gems) and len(hold) != howmany:
            break
        if len(hold) == howmany:
            if e-s+1 < cnt:
                flag = True
                cnt = e-s+1
                sh, eh = s, e
            hold[gems[s]] -= 1
            if not hold[gems[s]]:
                hold.pop(gems[s])
            s += 1
        elif i < len(gems):
            if not len(hold):
                hold[gems[i]] = 1
                s, e = i, i
            else:
                if gems[i] not in hold:
                    hold[gems[i]] = 0
                hold[gems[i]] += 1
                e = i
            i += 1

    if flag:
        return [sh+1, eh+1]
    return [1, len(gems)]
