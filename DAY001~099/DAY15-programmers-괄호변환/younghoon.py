def solution(p):    
    def divide(p):
        count = 0
        for i in range(len(p)):
            if p[i] == '(':
                count += 1
            else:
                count -= 1
            if count == 0:
                return p[:i+1], p[i+1:]
    def check(p):
        count = 0
        for i in range(len(p)):
            if p[i] == '(':
                count += 1
            else:
                if count == 0:
                    return False
                count -= 1
        return True
    result = ''
    if p == '':
        return p
    u, v = divide(p)
    if check(u) == True:
        return u + solution(v)
    else:
        temp = '('
        temp = temp + solution(v)
        temp = temp + ')'
        u = list(u[1:-1])
        for i in range(len(u)):
            if u[i] == '(':
                u[i] = ')'
            else:
                u[i] = '('
        return temp + "".join(u)
