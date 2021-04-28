import sys
si = sys.stdin.readline
sys.setrecursionlimit(100000)


def postorder(node):
    if node[-1]:
        postorder(node[-1])
    if node[1]:
        postorder(node[1])
    print(node[0])


def main():
    root = 0
    for num in sys.stdin:
        num = int(num)
        node = dict()
        node[0], node[1], node[-1] = num, 0, 0
        if not root:
            root = node
        else:
            pos = root
            while pos:
                if node[0] < pos[0]:
                    parent, prev = pos, -1
                    pos = pos[-1]
                else:
                    parent, prev = pos, 1
                    pos = pos[1]
            parent[prev] = node
    postorder(root)


if __name__ == '__main__':
    main()
