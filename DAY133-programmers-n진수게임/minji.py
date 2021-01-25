def convert(n, i):
    arr = "0123456789ABCDEF"
    q, r = divmod(i, n) #n진수
    if q == 0:
        return arr[r]
    else:
        return convert(n, q) + arr[r]
    

def solution(n, t, m, p):
    answer = ''
    can = []
    
    for i in range(t*m):
        conv = convert(n, i)
        for c in conv:
            can.append(c)
    
    for i in range(p-1, t*m, m):
        answer += can[i]
    return answer
