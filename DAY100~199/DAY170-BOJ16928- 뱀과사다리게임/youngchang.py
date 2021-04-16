N, M = map(int, input().split())

dic = dict()
for _ in range(N + M):
    x, y = map(int, input().split())
    dic[x] = y

q = [(1, 0)]
seen = set()
for curr, step in q:
    if curr == 100:
        break
    if curr > 100:
        continue
    if curr in seen: continue
    seen.add(curr)
    for i in range(1, 7):
        nxt = curr + i
        if nxt in dic:
            q.append((dic[nxt], step + 1))
        else:
            q.append((nxt, step + 1))

print(step)