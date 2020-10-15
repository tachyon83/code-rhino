N = int(input())
pixels = [input() for _ in range(N)]

def check(n, x=0, y=0):
    ret = ''
    areas = [(x, y), (x+n, y), (x, y+n), (x+n, y+n)]
    if n == 1:
        return ''.join(pixels[y][x] for x, y in areas)
    for X, Y in areas:
        ck = check(n//2, X, Y)
        if len(set(ck)) == 1:
            ret += ck[0]
        else:
            ret += f'({ck})'

    return ret
if N == 1:
    print(1)
else:
    print(f'({check(N//2)})')
