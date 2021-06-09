import sys
mod = 1000
n = (1<<25) // mod + 1
a = [0]*n
d = {str(i) for i in range(10)}
flag=False

while True:
    b = ''
    while True:
        ch = sys.stdin.read(1)
        if ch == ' ':
            break
        elif ch in d:
            b += ch
        else:
            flag=True
            break
    if flag:
        break
    x, y = int(b) % mod, int(b) // mod
    if not a[y] & (2<<x):
        print(b, end = ' ')
    a[y] |= (2<<x)
if b:
    x, y = int(b) % mod, int(b) // mod
    if not a[y] & (2**x):
        print(b, end = '')
