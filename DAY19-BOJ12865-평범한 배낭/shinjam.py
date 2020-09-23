N, K = map(int,input().split())
DP = {0:0} # 무게:가치
for _ in range(N):
    W, V = map(int,input().split())
    t = {}
    for w, v in DP.items():
        nw, nv = w + W, v + V
        if nw <= K and DP.get(nw,0) < nv:
            t[nw] = nv
    DP.update(t)
print(f'{max(DP.values())}')
