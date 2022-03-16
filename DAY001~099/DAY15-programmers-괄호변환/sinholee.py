def reverse(u):
    temp = ""
    for i in u[1:-1]:
        if i == "(":
            temp += ")"
        else:
            temp += "("
    return temp


def solution(p):
    if len(p) == 0:
        return ""
    cnt = 0
    is_balanced = True
    for i in range(len(p)+1):
        if i != 0 and cnt == 0:
            u = p[:i] # 균형잡힌 괄호 문자열
            v = p[i:]
            break
        if p[i] == "(":
            cnt += 1
            is_balanced = False
        else:
            cnt -= 1
            is_balanced = True
    if is_balanced:
        return u + solution(v)
    else:
        return "(" + solution(v) + ")" + reverse(u)