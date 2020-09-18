from collections import defaultdict

def solution(words):
    hash_dict = defaultdict(int)
    for word in words:
        s = ''
        for idx, val in enumerate(word):
            s += val
            hash_dict[s] += 1
    
    
    cnt = 0
    for word in words:
        s = ''
        for idx, val in enumerate(word):
            s += val
            cnt += 1
            if hash_dict[s] == 1:
                break
    return cnt
