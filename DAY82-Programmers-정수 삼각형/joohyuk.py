def solution(triangle):
    sz=len(triangle)
    for i in range(sz-1,0,-1):
        hold=-1
        for idx,e in enumerate(triangle[i]):
            if hold==-1:
                hold=e
                continue
            triangle[i-1][idx-1]+=max(hold,e)
            hold=e
    return triangle[0][0]
            
            
        
