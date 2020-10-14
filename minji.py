import sys

def sol(x, y, n):
    if n == 1:
        return image[y][x]

    a = int(n/2)

    r1 = sol(x, y, a)
    r2 = sol(x+a, y, a)
    r3 = sol(x, y+a, a)
    r4 = sol(x+a, y+a, a)

    if r1 == r2 == r3 == r4 and len(r1) == 1:
        return r1
    return "(" + r1 + r2 + r3 + r4 + ")"

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    image = []
    for _ in range(n):
        image.append(list(sys.stdin.readline().strip()))

    print(sol(0, 0, n))
