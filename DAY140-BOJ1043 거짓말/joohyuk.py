import sys
from collections import deque
si = sys.stdin.readline
graph, set_ppl_truth = [[] for _ in range(50+1)], set()
roots = [i for i in range(50+1)]
visited = [False for _ in range(50+1)]


def union(a, b):
    global roots, set_ppl_truth, graph, visited
    q = deque()

    aroot = find(a)
    if aroot in set_ppl_truth:
        roots[b] = aroot
        q.append(b)
        visited[b] = True
        while q:
            curr = q.popleft()
            for nxt in graph[curr]:
                if not visited[nxt]:
                    visited[nxt] = True
                    q.append(nxt)
                    union(a, nxt)
        return

    broot = find(b)
    if broot in set_ppl_truth:
        roots[a] = broot
        q = deque()
        q.append(a)
        visited[a] = True
        while q:
            curr = q.popleft()
            for nxt in graph[curr]:
                if not visited[nxt]:
                    visited[nxt] = True
                    q.append(nxt)
                    union(b, nxt)
        return

    roots[b] = aroot


def find(a):
    if roots[a] == a:
        return a
    roots[a] = find(roots[a])
    return roots[a]


def main():
    global roots, set_ppl_truth, graph, visited
    n, m = [int(e) for e in si().split()]
    info_ppl_truth = [int(e) for e in si().split()]
    set_ppl_truth = set(info_ppl_truth[1:])
    parties = []
    while m:
        m -= 1
        temp = [int(e) for e in si().split()]
        temp = temp[1:]
        parties.append(temp)
        for i in range(len(temp)-1):
            for j in range(1, len(temp)):
                graph[temp[i]].append(temp[j])
                graph[temp[j]].append(temp[i])

        if len(temp) > 1:
            for i in range(len(temp)-1):
                union(temp[i], temp[i+1])

    cnt = 0
    for party in parties:
        flag = False
        for person in party:
            if find(person) in set_ppl_truth:
                flag = True
                break
        if not flag:
            cnt += 1
    print(cnt)


if __name__ == '__main__':
    main()
