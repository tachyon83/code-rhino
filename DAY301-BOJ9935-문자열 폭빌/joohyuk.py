import sys
si = sys.stdin.readline

t = si()[:-1]
p = si()[:-1]
tsz, psz = len(t), len(p)
gone = [0 for _ in range(tsz)]


def check(i):
    global t, p, tsz, psz

    if i >= tsz:
        return False, i

    s, j = i, 0
    while i < tsz and j < psz:
        if j and t[i] == p[0]:
            flag, i = check(i)
            if not flag:
                return False, i
        if t[i] == p[j]:
            i += 1
            j += 1
        else:
            break

    if j == psz:
        for idx in range(i-1, s-1, -1):
            if not gone[idx]:
                gone[idx] = 1
        return True, i
    return False, i if j else i+1


i = 0
while i < tsz:
    flag, i = check(i)

cnt = 0
for i in range(tsz):
    if not gone[i]:
        cnt += 1
        print(t[i], end='')
if not cnt:
    print('FRULA')
