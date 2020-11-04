from collections import defaultdict

N, M, K = map(int, input().split())
FIRES = defaultdict(list)

for _ in range(M):
    y, x, m, s, d = map(int, input().split())
    FIRES[(x-1, y-1)].append((m, s, d))

def is_all_even_or_odd(fires):
    odd, even = False, False
    for m, s, d in fires:
        if d % 2 == 0:
            even = True
        else:
            odd = True
    return odd ^ even


def step1(FIRES):
    dx, dy = (0, 1, 1, 1, 0, -1, -1, -1), (-1, -1, 0, 1, 1, 1, 0, -1)
    tmp = defaultdict(list)
    for (x, y), val in FIRES.items():
        while val:
            m, s, d = val.pop()
            nx, ny = (x + s*dx[d])%N, (y + s*dy[d])%N
            tmp[(nx, ny)].append((m, s, d))
    FIRES.update(tmp)
    
    
def step2(FIRES):
    for key, val in FIRES.items():
        if len(val) >= 2:
            new_fires = []
            m_sum, s_sum, d_sum = map(sum, zip(*val))
            m, s = m_sum // 5, s_sum // len(val)
            if m:
                d = 0 if is_all_even_or_odd(val) else 1
                for v in range(4):
                    new_fires.append((m,s,v*2+d))
            FIRES[key] = new_fires

for _ in range(K):
    step1(FIRES)
    step2(FIRES)
    
ans = 0
for val in FIRES.values():
    ans += sum(map(lambda x: x[0], val)) if val else 0
    
print(ans)
