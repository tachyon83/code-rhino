import sys
from collections import deque
si = sys.stdin.readline


def isTransformable(given, elem):
    t, sz = 0, len(given)
    for i, e in enumerate(given):
        if e == elem[i]:
            t += 1
    if t == sz-1:
        return True
    return False


def solution(begin, target, words):
    vis, q = set(), deque()
    q.append((begin, 0))
    vis.add(begin)

    while q:
        curr, cnt = q.popleft()
        if curr == target:
            return cnt
        for e in words:
            if e not in vis and isTransformable(curr, e):
                vis.add(e)
                q.append((e, cnt+1))
    return 0
