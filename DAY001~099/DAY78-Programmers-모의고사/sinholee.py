def solution(answers):
    a = (1, 2, 3, 4, 5)
    b = ( 2, 1, 2, 3, 2, 4, 2, 5)
    c = ( 3, 3, 1, 1, 2, 2, 4, 4, 5, 5)
    dic = {1: 0, 2: 0, 3: 0}
    for i in range(len(answers)):
        if answers[i] == a[i % len(a)]:
            dic[1] += 1
        if answers[i] == b[i % len(b)]:
            dic[2] += 1
        if answers[i] == c[i % len(c)]:
            dic[3] += 1
    answer = []

    for key, value in dic.items():
        if value == max(dic.values()):
            answer.append(key)

    answer = sorted(answer)
    return answer
