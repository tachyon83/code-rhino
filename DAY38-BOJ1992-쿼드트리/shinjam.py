
N = int(input())
pixels = [input() for _ in range(N)]

def qt(n, x=0, y=0):
    if n == 1:
        return pixels[y][x]
    size = n // 2
    areas = [
        qt(size, x, y),
        qt(size, x + size, y),
        qt(size, x, y + size),
        qt(size, x + size, y + size)
    ]
    if len(set(areas)) == 1 and len(areas[0]) == 1:
        return areas[0]
    return f"({''.join(areas)})"
print(qt(N))
