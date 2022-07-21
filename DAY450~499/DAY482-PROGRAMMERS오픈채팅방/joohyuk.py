userMap = dict()


def solution(record):
    hist = []
    for e in record:
        l = e.split()
        if l[0] == 'Enter':
            userMap[l[1]] = l[2]
            hist.append([1, l[1]])
        elif l[0] == 'Leave':hist.append([0, l[1]])
        else:userMap[l[1]] = l[2]

    answer = []
    for e in hist:
        if e[0]:answer.append(userMap[e[1]]+'님이 들어왔습니다.')
        else:answer.append(userMap[e[1]]+'님이 나갔습니다.')
    return answer
