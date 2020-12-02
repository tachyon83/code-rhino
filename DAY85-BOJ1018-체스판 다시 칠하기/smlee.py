n, m = map(int, input().split())
l = []
cnt = []

for _ in range(n):
    l.append(input())

for a in range(n - 7):
    for i in range(m - 7):
        w_paint = 0
        b_paint = 0
        for b in range(a, a + 8):
            for j in range(i, i + 8):
                if (j + b)%2 == 0:
                    if l[b][j] != 'W': w_paint += 1  
                    if l[b][j] != 'B': b_paint += 1
                else :
                    if l[b][j] != 'B': w_paint += 1
                    if l[b][j] != 'W': b_paint += 1
        cnt.append(w_paint)
        cnt.append(b_paint)

print(min(cnt))   
