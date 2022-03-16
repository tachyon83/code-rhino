N,k,s=int(input()),int(input()),1
e=N*N
while s<e:
    cnt=0
    mid=(s+e)//2
    for i in range(1,N+1):cnt+=min(mid//i,N)
    if cnt>=k: e=mid
    else: s=mid+1
print(s)
