from collections import defaultdict

def solution(words):
    hash_dict = defaultdict(int)
    for word in words:
        for i in range(len(word)):            
            hash_dict[word[:i + 1]] += 1
    
    
    cnt = 0
    for word in words:
        for i in range(len(word)):  
            cnt += 1
            if hash_dict[word[:i + 1]] == 1:
                break
    return cnt
