import sys

def sol():
    cnt = 1
    end = meetings[0][1]
    for i in range(1, n):
        if meetings[i][0] >= end:
            cnt += 1
            end = meetings[i][1]
    return cnt

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    meetings = []
    for i in range(n):
        s, e = map(int, sys.stdin.readline().split())
        meetings.append([s, e])

    meetings.sort(key=lambda x: (x[1], x[0]))

    print(sol())
