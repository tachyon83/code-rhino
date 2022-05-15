from collections import deque
import copy

def solution(info, edges):
    g,answer=[[]for _ in range(len(info))],0
    for edge in edges:
        a,b=edge
        g[a].append(b)
        

    def solve(curr,children,sheep,wolf):
        nonlocal answer

        if info[curr]:wolf+=1
        else: sheep+=1

        if wolf>=sheep:return
        children.popleft()        
        answer=max(answer,sheep)

        for nx in g[curr]:children.append(nx)
        if not children:return

        for _ in range(len(children)):
            solve(children[0],copy.deepcopy(children),sheep,wolf)
            children.append(children.popleft())

    q=deque()
    q.append(0)
    solve(0,q,0,0)
    return answer
