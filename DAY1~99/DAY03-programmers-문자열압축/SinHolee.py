def solution(s):
    answer = 999999999
    # 한번 압축할때 필요한 갯수

    for i in range(1, len(s)+1): # 최악의 경우 다 읽기
        temp = 0
        before = ""
        cnt = 0
        for idx in range(0, len(s), i):
            word = s[idx:idx+i]
            if before != word:
                temp += len(word)
                if cnt >1:
                    temp += len(str(cnt))
                cnt = 1
            else:
                cnt += 1

            before = word
            if temp > answer:
                break
        if answer > temp:
            answer = temp
    return answer