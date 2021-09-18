import sys
input=sys.stdin.readline

R,C,M=list(map(int,input().split()))
shark=[]
for _ in range(M):
    shark.append(list(map(int,input().split())))
arr=[[[] for _ in range(C)] for _ in range(R)]

for k in range(M):
    r,c,s,d,z=shark[k]
    if z==-1:
        continue
    arr[r-1][c-1].append(k)

result=0
for i in range(C):


    for j in range(R):
        if arr[j][i]!=[]:
            arr[j][i].sort()
            result+=shark[arr[j][i][-1]][4]
            shark[arr[j][i][-1]][4]=-1
            arr[j][i].pop()
            
            break
    
    for k in range(M):
        r,c,s,d,z=shark[k]
        if z==-1:
            continue
        arr[r-1][c-1].remove(k)

        if d==1 or d==2:
            s=s%(2*(R-1))
        else:
            s=s%(2*(C-1))
        while s!=0:
            if d==1:
                if s>=r-1:
                    s-=r-1
                    r=1
                    d=2
                else:
                    r-=s
                    s=0
            elif d==2:
                if s>=R-r:
                    s-=(R-r)
                    r=R
                    d=1
                else:
                    r+=s
                    s=0
            elif d==3:
                if s>=C-c:
                    s-=(C-c)
                    c=C
                    d=4
                else:
                    c+=s
                    s=0
            elif d==4:
                if s>=c-1:
                    s-=c-1
                    c=1
                    d=3
                else:
                    c-=s
                    s=0
        shark[k][0]=r
        shark[k][1]=c
        shark[k][3]=d
        arr[r-1][c-1].append(k)

    for k in range(M):
        r,c,s,d,z=shark[k]
        if z==-1:
            continue
        if len(arr[r-1][c-1])!=1:
            for j in arr[r-1][c-1]:
                if shark[j][4]>z:
                    shark[k][4]=-1
                    arr[r-1][c-1].remove(k)
                    break

print(result)
            
            


