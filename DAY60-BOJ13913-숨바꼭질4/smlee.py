import sys
input = sys.stdin.readline

n,k = map(int, input().split())
N = 100001
move = [-1]*N
anw = []
q = [n]
res,cnt = -1,0
while q and res == -1:
    tq = []
    for i in q:
        if i == k:
            res = cnt
            break
        if i+1 < N and move[i+1] == -1:            
            move[i+1] = i
            tq += [i+1]
        if i > 0 and move[i-1] == -1:
            move[i-1] = i
            tq += [i-1]
        if i*2 < N and move[i*2] == -1:
            move[i*2] = i
            tq += [i*2]
    q = tq
    cnt += 1

print(res)

while k != n:
    anw += [k]
    k = move[k]
anw += [n]
print(*anw[::-1])
