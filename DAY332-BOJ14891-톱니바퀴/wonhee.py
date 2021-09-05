import sys
input=sys.stdin.readline

arr=[]
arr.append(list(map(int,input().strip())))
arr.append(list(map(int,input().strip())))
arr.append(list(map(int,input().strip())))
arr.append(list(map(int,input().strip())))

K=int(input())
for _ in range(K):
    num,dir=map(int,input().split())
    num-=1
    rotation=[[num,dir]]
    left_dir=dir
    for i in range(num-1,-1,-1):
        if arr[i][2]!=arr[i+1][6]:
            left_dir=-left_dir
            rotation.append([i,left_dir])
        else:
            break
    right_dir=dir
    for i in range(num,3):
        if arr[i][2]!=arr[i+1][6]:
            right_dir=-right_dir
            rotation.append([i+1,right_dir])
        else:
            break
    for num,dir in rotation:
        if dir==-1:
            arr[num].append(arr[num][0])
            arr[num].pop(0)
        else:
            arr[num].insert(0,arr[num][-1])
            arr[num].pop(-1)
result=0
for i in range(0,4):
    if arr[i][0]==1:
        result+=pow(2,i)
print(result)