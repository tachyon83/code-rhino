N=int(input())
cnt=0
arr=[]
def hanoi(n,start,end,mid):
    global cnt
    cnt+=1
    if n==1:
        arr.append((start,end))
        return
    hanoi(n-1,start,mid,end)
    arr.append((start,end))
    hanoi(n-1,mid,end,start)

hanoi(N,1,3,2)
print(cnt)
for a,b in arr:
    print(a,b)
