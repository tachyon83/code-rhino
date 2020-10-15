import sys
# sys.stdin = open("input.txt", "r")
N = int(sys.stdin.readline())
def getParent(parent : list, x : str):
    if parent[x] == x:
        return x
    else:
        return getParent(parent, parent[x])

def unionParent(parent: list, a : str, b : str):
    a = getParent(parent, a)
    b = getParent(parent, b)
    if a!=b:
        parent[b] = a
        friends_cnt[a] += friends_cnt[b]
    print(friends_cnt[a])


for _ in range(N):
    relations = int(sys.stdin.readline())
    parent, friends_cnt = {}, {}
    for i in range(relations):
        a,b = sys.stdin.readline().split()
        if a not in parent:
            parent[a] = a
            friends_cnt[a] = 1
        if b not in parent:
            parent[b] = b
            friends_cnt[b] = 1
        unionParent(parent, a,b)
