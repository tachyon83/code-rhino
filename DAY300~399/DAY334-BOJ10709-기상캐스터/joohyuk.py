import sys
si = sys.stdin.readline

h, w = [int(e) for e in si().split()]
for _ in range(h):
    row = [e for e in si().strip()]
    cnt = 0
    for e in row:
        if e == '.':
            if not cnt:
                print(-1, end=' ')
            else:
                print(cnt, end=' ')
                cnt += 1
        else:
            print(0, end=' ')
            cnt = 1
    print()
