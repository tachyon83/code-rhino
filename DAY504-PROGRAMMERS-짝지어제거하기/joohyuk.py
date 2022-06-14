def solution(t):
    i,st=0,[]
    while i<len(t):
        if not len(st) or st[-1]!=t[i]:st.append(t[i])
        else:st.pop()
        i+=1
    return 1 if len(st)==0 else 0
        
    
    
