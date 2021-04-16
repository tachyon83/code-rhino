from collections import deque

ch_word = lambda a, b: sum((1 if x != y else 0) for x,y in zip(a,b)) == 1

def solution(begin, target, words):
    q = deque()
    dic = dict()
    q.append((begin, 0))
    dic[begin] = set(filter(lambda x:ch_word(x, begin), words))

    
    for w in words:
        dic[w] = set(filter(lambda x:ch_word(x, w), words))
    
    while q:
        cur, level = q.popleft()
        if level > len(words):
            return 0
        for w in dic[cur]:
            if w == target:
                return level + 1
            else: 
                q.append((w, level + 1))
    return 0
