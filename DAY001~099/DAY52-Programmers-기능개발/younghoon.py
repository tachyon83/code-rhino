from collections import deque
def solution(progresses, speeds):
    time = deque()
    for i in range(len(progresses)):
        remain = (100-progresses[i]) // speeds[i]
        if not (100-progresses[i]) % speeds[i] == 0 :
            remain += 1
        time.append(remain)
        
    front = 0
    result = []
    for i in range(len(progresses)):
        if time[front] < time[i]:
            result.append(i-front)
            front = i
    result.append(len(progresses)-front)
    return result
