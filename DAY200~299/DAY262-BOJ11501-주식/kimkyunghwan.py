T=int(input())



for i in range(T):
    ans=0
    n=int(input())
    # pos[i]에는 value가 i인 원소들 중 index가 가장 큰 것이 들어간다
    pos=[-1]*10001 
    
    A=list(map(int,input().split()))
    
    for j in range(n):
        pos[A[j]]=j
    
    #주식을 팔 시작 위치, 끝은 pos[j]-1
    temp=0
    
    for j in range(10000,0,-1):
        total=0
        #배열에 없거나 자기보다 큰 수가 자기 앞에 나온 경우
        if pos[j]==-1 or pos[j]<temp: continue
        #하지만 자기보다 큰 수가 자기 바로 앞인 경우에는 
        if pos[j]==temp:
            temp+=1
            continue
        
        for k in range(temp,pos[j]):
            total+=A[k]
    
        ans+=(pos[j]-temp)*j-total
        temp=pos[j]+1
        
    print(ans)
