import sys
input=sys.stdin.readline

n,k=map(int,input().split())
arr=list(map(int,input().split()))
code=[]
cnt=0

def idxInCode(arr,val):
    for i in range(len(arr)):
        if  arr[i][0]==val:
            return i
    return -1
def findNextIdx(arr,val,idx):
    try:
        return arr.index(val,idx+1)
    except ValueError:
        return 101
    

for idx,now in enumerate(arr):
    if len(code)!=n:
        if idxInCode(code,now)==-1:#코드 안에 없음
            code.append((now,findNextIdx(arr,now,idx)))
        else:
            code[idxInCode(code,now)]=(now,findNextIdx(arr,now,idx))
        continue
    
    i=idxInCode(code,now)
    nidx=findNextIdx(arr,now,idx)
    if i==-1:#코드 안에 없음 
        code[idxInCode(code,max(code,key=lambda x:x[1])[0])]=(now,nidx)
        cnt+=1
    else:
        code[i]=(now,nidx)

    
print(cnt)
