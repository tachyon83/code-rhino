def comp(i, s):
    if i > len(s)//2:
        return len(s)
    st, cnt = s[:i], 0
    while s[:i] == st:
        cnt += 1
        s = s[i:]
    if cnt == 1:
        cnt = ''
    return len(str(cnt))+i+comp(i, s)


def solution(s):
    if len(s) == 1:
        return 1
    answer, slen = 1001, len(s)
    for i in range(1, slen//2+1):
        answer = min(answer, comp(i, s))
    return answer
