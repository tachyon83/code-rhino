import sys

def sol():
    s = set([])
    m = 0
    for i in range(2, int(x**0.5)+2):
        d, n = [], x
        while n > 0:
            d.append(n % i)
            n //= i

        if d == list(reversed(d)):
            s.add(i)

        m = i
    for i in range(m, 0, -1):
        if x % i == 0:
            b = x // i-1
            if b*b-1 > x:
                s.add(b)

    for e in sorted(s):
        print(e)

if __name__ == "__main__":
    x = int(sys.stdin.readline())

    sol()
