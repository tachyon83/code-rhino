import sys

def sol():
    dic = dict()
    for p in pu:
        if p not in dic:
            dic[p] = 0
        dic[p] += 1

    ans = dict()
    for d in dic:
        cur = 0
        for w in words:
            check = False
            if d not in w:
                continue
            for t in w:
                if t not in dic or w[t] > dic[t]:
                    check = True
                    break
            if check:
                continue
            cur += 1
        if cur not in ans:
            ans[cur] = ''
        ans[cur] += d
    print(''.join(sorted(' '.join(ans[min(ans)]).split())),
          min(ans), ''.join(sorted(' '.join(ans[max(ans)]).split())), max(ans))


if __name__ == "__main__":
    words = []
    while True:
        word = sys.stdin.readline().strip()
        if word == '-':
            break
        tmp = dict()
        for w in word:
            if w not in tmp:
                tmp[w] = 0
            tmp[w] += 1
        words.append(tmp)

    while True:
        pu = sys.stdin.readline().strip()
        if pu == '#':
            break
        sol()
