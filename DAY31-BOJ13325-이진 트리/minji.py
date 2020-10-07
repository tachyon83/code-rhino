import sys

def sol():
    for i in range((1<<(k+1))-1, 0, -1):
        left = i<<1
        right = left+1

        path[i] = max(path[left]+w[left], path[right]+w[right])
        sum_[i] = sum_[left] + sum_[right] + (path[i]-path[left]) + (path[i]-path[right])

    print(sum_[1])

if __name__ == "__main__":
    k = int(sys.stdin.readline())
    n = (1<<(k+1))-1
    max_ = 1<<(k+2)

    w = [0 for _ in range(max_)]
    path = [0 for _ in range(max_)]
    sum_ = [0 for _ in range(max_)]

    root = [0, 0]
    t = list(map(int, sys.stdin.readline().split()))
    w = root + t + w

    sol()
