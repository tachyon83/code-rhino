def solution(msg):

    d = dict()
    for i in range(26):
        d[chr(ord('A')+i)] = i+1
        if 'Z' in d:
            k = d['Z']+1

    answer = []
    while len(msg):
        temp, pos = msg, len(msg)
        while temp not in d:
            pos -= 1
            temp = temp[:pos]
        answer.append(d[temp])
        msg = msg[pos:]
        if len(msg):
            d[temp+msg[0]] = k
            k += 1

    return answer
