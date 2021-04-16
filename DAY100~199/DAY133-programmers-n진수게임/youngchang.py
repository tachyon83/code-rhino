NOTATION = '0123456789ABCDEF'
def numeral_system(number, base):
    q, r = divmod(number, base)
    n = NOTATION[r]
    return numeral_system(q, base) + n if q else n
def solution(n, t, m, p):
    limit = t*m
    blank = ''
    for i in range(limit+1):
        blank+=str(numeral_system(i,n))
    blank = list(blank)
    length = len(blank)
    return ''.join(blank[p-1:length:m])[:t]