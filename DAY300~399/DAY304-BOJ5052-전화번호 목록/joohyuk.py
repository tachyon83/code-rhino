import sys
si = sys.stdin.readline
phone, s = dict(), ''


def register(d, i):
    global s
    ret = 0
    if 'e' in d:ret = 1
    if i == len(s):
        if len(d.keys()):ret = 1
        d['e'] = 0
        return ret

    if s[i] not in d:d[s[i]] = dict()
    return ret | register(d[s[i]], i+1)


t = int(si())
while t:
    t -= 1
    n, phone, ret = int(si()), dict(), 0
    for _ in range(n):
        s = si()[:-1]
        ret |= register(phone, 0)
    print('NO' if ret else 'YES')
