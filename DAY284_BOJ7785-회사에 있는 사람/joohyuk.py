import sys
si = sys.stdin.readline

n, room = int(si()), set()
while n:
    n -= 1
    a, b = [e for e in si().split()]
    if b == 'enter':room.add(a)
    else:room.remove(a)

room = sorted(list(room), reverse=True)
for p in room:print(p)
