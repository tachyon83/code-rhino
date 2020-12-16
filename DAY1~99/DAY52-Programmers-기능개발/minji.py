from collections import deque
def solution(pro, spe):
    answer = []
    time, cnt = 0, 0
    p = deque(pro)
    s = deque(spe)
    
    while p:
        if (p[0] + time*s[0]) >= 100:
            p.popleft()
            s.popleft()
            cnt += 1
        else:
            if cnt > 0:
                answer.append(cnt)
                cnt = 0
            time += 1
    answer.append(cnt)
    return answer
