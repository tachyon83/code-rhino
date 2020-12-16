import sys

def sol():
    ropes.sort()

    max_ = -1
    for i, v in enumerate(ropes[::-1]):
        if max_ < v * (i+1):
            max_ = v * (i+1)
    return max_

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    ropes = [int(sys.stdin.readline()) for _ in range(n)]
    print(sol())
