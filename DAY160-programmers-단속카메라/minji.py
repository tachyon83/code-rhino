def solution(routes):
    answer = 0
    routes.sort(key=lambda x:x[1])
    ch = [0] * len(routes)

    for i in range(leng):
        if ch[i] == 0:
            cam = routes[i][1]
            answer += 1
        for j in range(i+1, leng):
            if routes[j][0] <= cam <= routes[j][1] and ch[j] == 0:
                ch[j] = 1
    return answer
