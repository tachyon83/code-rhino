import sys
input=sys.stdin.readline

T=int(input())
for ___ in range(T):
    p,n,arr=input().rstrip(),int(input()),input()
    if n==0:
        srr=[]
    else:
        arr=list(int(i) for i in arr[1:-2].split(","))
    
    l,r,rev=0,n-1,False
    for c in p:
        if c=='R':
            rev=not rev
        elif rev:
            r-=1
        else:
            l+=1
    if r+1<l:
        print('error')
    else:
        temp=""
        if rev:
            for i in range(r,l-1,-1):
                temp+=str(arr[i])+","
        else:
            for i in range(l,r+1):
                temp+=str(arr[i])+","
        print('['+temp[:-1]+']')
