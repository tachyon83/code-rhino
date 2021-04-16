nmap = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}


def solution(n, t, m, p):
    num, s = 0, ''
    while num < t*m:
        temp, k = '', num
        while k//n:
            if k % n >= 10:
                temp2 = nmap[k % n]
            else:
                temp2 = str(k % n)
            temp = temp2+temp
            k //= n
        if not num:
            temp += str(0)
        if k:
            if k >= 10:
                temp2 = nmap[k]
            else:
                temp2 = str(k)
            temp = temp2+temp
        s += temp
        num += 1

    cnt, answer, pos = 0, '', p-1
    while cnt < t:
        answer += s[pos]
        cnt += 1
        pos += m
    return answer
