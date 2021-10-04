import sys
preo, posto, ino = [], [], []

def solve(pre_s, pre_e, in_s, in_e):
    idx = ino.index(preo[pre_s])
    pos = idx-in_s+pre_s
    if idx > in_s:solve(pre_s+1, pos, in_s, idx-1)
    if idx < in_e:solve(pos+1, pre_e, idx+1, in_e)
    posto.append(preo[pre_s])

for line in sys.stdin:
    preo, ino = line.split()
    posto, n = [], len(preo)
    solve(0, n-1, 0, n-1)
    print(''.join(posto))
