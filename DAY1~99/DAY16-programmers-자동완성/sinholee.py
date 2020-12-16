def solution(words):
    answer = 0
    dic = {}
    for word in words:
        temp = dic
        for ch in word:
            if temp.get(ch) is None:
                temp[ch] = {'num' : 1}
            else:
                temp[ch]['num'] += 1
            temp = temp[ch]
    # search
    for word in words:
        cnt = 0
        temp = dic
        for ch in word:
            if temp[ch]['num'] == 1:
                answer += cnt + 1
                break
            cnt+=1
            temp = temp[ch]
        else:
            answer += cnt
    return answer