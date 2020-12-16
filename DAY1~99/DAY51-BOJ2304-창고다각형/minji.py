import sys

def sol(house, max_, min_):
    left = [0] * max_
    right = [0] * max_
    ans = 0

    left[0] = house[0]
    right[-1] = house[max_-1]

    for i in range(1, max_):
        if left[i-1] > house[i]:
            left[i] = left[i-1]
        else:
            left[i] = house[i]

    for i in range(max_-2, min_-1, -1):
        if right[i+1] > house[i]:
            right[i] = right[i+1]
        else:
            right[i] = house[i]

    for i in range(max_):
        if left[i] >= right[i]:
            ans += right[i]
        else:
            ans += left[i]

    return ans

if __name__ == "__main__":
    size = 1001
    n = int(sys.stdin.readline())
    pos = []
    house = [0] * size

    for _ in range(n):
        p, h = list(map(int, sys.stdin.readline().split()))
        house[p] = h
        pos.append(p)

    pos_min = min(pos)
    pos_max = max(pos)

    print(sol(house, pos_max+1, pos_min))
