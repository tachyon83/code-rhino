# 균형잡인 문자열 반환
def get_balanced(case):
    cnt = {'(': 0, ')': 0}
    for idx, val in enumerate(case):
        cnt[val] += 1
        if cnt['('] == cnt[')']:
            return idx + 1
    return False
    
# 옳바른 문자열 채크
def is_correct(case):
    stack = []
    for x in case:
        if x == '(':
            stack.append(x)
        elif x == ')':
            if not stack or stack.pop() != '(':
                return False
    return True
        
def check_condition(u, v):
    if not u:
        return ''
    b_idx = get_balanced(v)
    if is_correct(u):
        return u + check_condition(v[:b_idx], v[b_idx:])
    ret = f'({check_condition(v[:b_idx], v[b_idx:])})'
    for x in range(1, len(u) - 1):
        if u[x] == '(':
            ret += ')'
        elif u[x] == ')':
            ret += '('
    return ret


def solution(p):
    ans = ''
    if p:
        b_idx = get_balanced(p)
        ans = check_condition(p[:b_idx], p[b_idx:])
    return ans
