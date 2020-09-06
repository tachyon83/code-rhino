# 문자열 나누기
def divide(s, l):
    ret, start = [], 0
    while start < len(s):
        ret.append(s[start:start + l])
        start += l
    return ret

def solution(s):
    ans = float('inf')
    for l in range(1, len(s) + 1):
        divided = divide(s, l) + ['']
        ret = ''
        cnt = 1
        for idx in range(1, len(divided)):
            now, before = divided[idx], divided[idx - 1]
            if now == before:
                cnt += 1
            else:
                ret += str(cnt) if cnt > 1 else ''
                ret += divided[idx - 1]
                cnt = 1

        ans = min(ans, len(ret)) 
    
    return ans
