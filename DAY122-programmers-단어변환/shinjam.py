from collections import deque

# 하나만 다른지 채크
def check(current, word):
    cnt = 0
    for a, b in zip(current, word):
        if a != b:
            cnt += 1
    
    return True if cnt == 1 else False

# 각 경우의 수 탐색
def bfs():
    queue = deque([[begin, []]])
    while queue:
        current, history = queue.popleft()
        
        
        if current == target:
            return len(history)
        
        for word in words:
            if check(current, word) and not word in history:
                new_history = history.copy()
                new_history.append(word)
                queue.append([word,new_history])

    return 0

def solution(a, b, c):
    global begin, target, words
    begin, target, words = a, b, c
    
    ret = bfs()
    
    
    return ret
