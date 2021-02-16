def solution(name):
    abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    sz = len(abc)
    abc1, abc2, i, j = dict(), dict(), 0, sz

    for c in abc:
        abc1[c], abc2[c] = i, j % sz
        i += 1
        j -= 1

    cnt = [0 for _ in range(len(name))]
    for i, e in enumerate(name):
        cnt[i] = min(abc1[e], abc2[e])

    answer = sum(cnt)
    return answer
