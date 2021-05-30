import sys
si = sys.stdin.readline

n, r, mx = int(si()), [], 0
for _ in range(n):r.append(int(si()))
r.sort()
for i, e in enumerate(r):mx = max(mx, (n-i)*e)
print(mx)
