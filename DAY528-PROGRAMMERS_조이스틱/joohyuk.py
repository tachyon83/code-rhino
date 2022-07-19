def solution(name):
    abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    sz = len(abc)
    abc1, abc2, i, j = dict(), dict(), 0, sz

    for c in abc:
        abc1[c], abc2[c] = i, j % sz
        i += 1
        j -= 1

    sz = len(name)
    cnt = [0 for _ in range(sz)]
    for i, e in enumerate(name):
        cnt[i] = min(abc1[e], abc2[e])

    i = ans = 0
    while True:
        ans += cnt[i]
        cnt[i] = 0
        if not sum(cnt):return ans
        l, r = 1, 1
        while not cnt[i-l]:l += 1
        while not cnt[i+r]:r += 1
        ans += l if l < r else r
        i += -l if l < r else r
