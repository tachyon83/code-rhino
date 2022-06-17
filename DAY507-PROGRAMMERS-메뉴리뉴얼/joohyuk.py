from itertools import combinations as cb


def solution(orders, course):
    cand, ans = dict(), []
    for order in orders:
        for v in course:
            cbr = cb(order, v)
            for e in cbr:
                temp = ''.join(sorted(e))
                if temp not in cand:
                    cand[temp] = 0
                cand[temp] += 1

    course, mxPerLen = set(course), [0 for _ in range(10+1)]
    for key in cand:
        l = len(key)
        mxPerLen[l] = max(mxPerLen[l], cand[key])
    for key in cand:
        if mxPerLen[len(key)] >= 2 and len(key) in course and cand[key] >= mxPerLen[len(key)]:
            ans.append(key)
    return sorted(ans)
