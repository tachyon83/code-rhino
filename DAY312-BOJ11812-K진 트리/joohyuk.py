import sys
si = sys.stdin.readline

n, k, q = [int(e) for e in si().split()]


def solve(a, b, k):
    ret = 0

    i, va, ra = 0, 1, 0
    while a > 1 and a > va:
        ra = va
        va += k**i
        i += 1
    if a < va:
        i -= 1
        va -= k**i
        ra -= k**(i-1)
    da = i

    i, vb, rb = 0, 1, 0
    while b > 1 and b >= vb:
        rb = vb
        vb += k**i
        i += 1
    if b < vb:
        i -= 1
        vb -= k**i
        rb -= k**(i-1)
    db = i

    if a == b:return ret
    if da > db:
        a, b = b, a
        da, db = db, da
        va, vb = vb, va
        ra, rb = rb, ra

    while da != db:
        rd = 1 if (b-1) % k else 0
        b = (b-1)//k+rd
        vb = rb
        db -= 1
        rb = rb-k**(db-1) if db else 0
        ret += 1

    while a != b:
        rd = 1 if (a-1) % k else 0
        a = (a-1)//k+rd
        va = ra
        da -= 1
        ra -= k**da

        rd = 1 if (b-1) % k else 0
        b = (b-1)//k+rd
        vb = rb
        db -= 1
        rb -= k**db
        ret += 2

    return ret


while q:
    q -= 1
    a, b = [int(e) for e in si().split()]
    if k == 1:print(abs(a-b))
    else:print(solve(a, b, k))
