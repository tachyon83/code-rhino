import sys
from collections import deque
si = sys.stdin.readline


def main():
    n, ps = int(si()), 0
    weights = [int(e) for e in si().split()]
    weights.sort()
    for weight in weights:
        if weight > ps+1:
            return ps+1
        else:
            ps += weight
    return ps+1


if __name__ == '__main__':
    print(main())
