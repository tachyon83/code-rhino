import sys

def find(x):
    if x == parent[x]:
        return x
    else:
        parent_x = find(parent[x])
        parent[x] = parent_x
        return parent[x]

def union(x, y):
    root_x = find(x)
    root_y = find(y)

    if root_x != root_y:
        parent[root_y] = root_x
        num[root_x] += num[root_y]

if __name__ == "__main__":
    c = int(sys.stdin.readline())

    for i in range(c):
        parent = dict()
        num = dict()

        f = int(sys.stdin.readline())

        for _ in range(f):
            x, y = sys.stdin.readline().split()

            if x not in parent:
                parent[x] = x
                num[x] = 1
            if y not in parent:
                parent[y] = y
                num[y] = 1

            union(x, y)
            print(num[find(x)])
