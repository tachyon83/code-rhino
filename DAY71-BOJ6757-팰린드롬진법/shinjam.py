def convert_base(n, b):
    if n < b:
        return [n]
    return convert_base(n//b, b) + [n%b]

def get_cands(n,ret=set()):
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            ret |= {i-1, n//i-1}
        ret.add(i)
    return ret - {0,1}

n = int(input())

for b in sorted(get_cands(n)):
    bases = convert_base(n, b)
    if bases == bases[::-1]:
        print(b)
