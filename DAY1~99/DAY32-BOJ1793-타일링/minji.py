import sys

def dp(n):
    d = [1, 1, 3]
    for i in range(3, n+1):
        d.append(d[i - 1] + 2 * d[i - 2])
    return d[n]

while True:
    try:
        print(dp(int(sys.stdin.readline())))
    except:
        break
