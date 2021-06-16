N=int(input())
A=list(map(int,input().split()))
A.sort()
M=1

for i in range(N): 
    if(M<A[i]):
        
        break
    
    
    else: M+=A[i]

print(M)
