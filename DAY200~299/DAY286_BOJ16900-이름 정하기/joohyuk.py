import sys
si = sys.stdin.readline

s, k = [e for e in si().split()]
sz, k, shared, j = len(s), int(k), 0, 0

for i in range(1, sz):
    if s[j] == s[i]:
        j += 1
        shared += 1
    elif s[0] == s[i]:
        j, shared = 1, 1

if sz > 1 and s[i] != s[j-1]:
    shared = 0
print(sz*k-(k-1)*shared)
