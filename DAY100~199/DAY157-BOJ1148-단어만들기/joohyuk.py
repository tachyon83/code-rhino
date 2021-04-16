import sys
si = sys.stdin.readline


def solve(s):
    global words
    given = dict()
    for e in s:
        if e not in given:
            given[e] = 0
        given[e] += 1

    cnt = dict()
    for must in given:
        curr = 0
        for word in words:
            flag = False
            if must not in word:
                continue
            for c in word:
                if c not in given or word[c] > given[c]:
                    flag = True
                    break
            if flag:
                continue
            curr += 1
        if curr not in cnt:
            cnt[curr] = ''
        cnt[curr] += must

    print(''.join(sorted(' '.join(cnt[min(cnt)]).split())), min(
        cnt), ''.join(sorted(' '.join(cnt[max(cnt)]).split())), max(cnt))


words = []
while True:
    s = si()[:-1]
    if s[0] == '-':
        break

    temp = dict()
    for e in s:
        if e not in temp:
            temp[e] = 0
        temp[e] += 1
    words.append(temp)

while True:
    s = si()[:-1]
    if s[0] == '#':
        break
    solve(s)
