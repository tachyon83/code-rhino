import sys
from collections import deque
si = sys.stdin.readline


def main():
    n = int(si())
    parents = [int(e) for e in si().split()]
    children_num = [0]*n
    k = int(si())
    children, roots = dict(), set()
    for i, node in enumerate(parents):
        if node != -1:
            children_num[node] += 1
            if node not in children:
                children[node] = set()
            children[node].add(i)
        else:
            roots.add(i)

    q, cnt = deque(), 0
    for e in roots:
        q.append(e)
    while q:
        curr = q.popleft()
        if curr == k:
            children_num[parents[curr]] -= 1
            if not children_num[parents[curr]]:
                cnt += 1
            continue
        if curr not in children:
            cnt += 1
        else:
            for elem in children[curr]:
                q.append(elem)
    print(cnt)


if __name__ == '__main__':
    main()
