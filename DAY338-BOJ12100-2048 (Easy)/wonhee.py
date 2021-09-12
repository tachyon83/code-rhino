import sys
from copy import deepcopy
input=sys.stdin.readline
N=int(input())
arr,arr2=[],[]
for _ in range(N):
    arr.append(list(map(int,input().split())))

def movingArr(n):
    if n==0:
        for i in range(N):
            cnt,prev = 0,0
            for j in range(N):
                if arr2[i][j] != 0:
                    if prev == 0:
                        prev = arr2[i][j]
                    else:
                        if prev == arr2[i][j]:
                            arr2[i][cnt] = prev * 2
                            prev = 0
                        else:
                            arr2[i][cnt] = prev
                            prev = arr2[i][j]
                        cnt+=1
            if prev != 0:
                arr2[i][cnt] = prev
                cnt+=1
            for j in range(cnt,N):
                arr2[i][j] = 0
    
    elif n==1:
        for i in range(N):
            cnt,prev = N-1,0
            for j in range(N-1,-1,-1):
                if arr2[i][j] != 0:
                    if prev == 0:
                        prev = arr2[i][j]
                    else:
                        if prev == arr2[i][j]:
                            arr2[i][cnt] = prev * 2
                            prev = 0
                        else:
                            arr2[i][cnt] = prev
                            prev = arr2[i][j]
                        cnt-=1
            if prev != 0:
                arr2[i][cnt] = prev
                cnt-=1
            for j in range(cnt,-1,-1):
                arr2[i][j] = 0

    elif n==2:
        for i in range(N):
            cnt,prev = 0,0
            for j in range(N):
                if arr2[j][i] != 0:
                    if prev == 0:
                        prev = arr2[j][i]
                    else:
                        if prev == arr2[j][i]:
                            arr2[cnt][i] = prev * 2
                            prev = 0
                        else:
                            arr2[cnt][i] = prev
                            prev = arr2[j][i]
                        cnt+=1
            if prev != 0:
                arr2[cnt][i] = prev
                cnt+=1
            for j in range(cnt,N):
                arr2[j][i] = 0
    
    elif n==3:
        for i in range(N):
            cnt,prev = N-1,0
            for j in range(N-1,-1,-1):
                if arr2[j][i] != 0:
                    if prev == 0:
                        prev = arr2[j][i]
                    else:
                        if prev == arr2[j][i]:
                            arr2[cnt][i] = prev * 2
                            prev = 0
                        else:
                            arr2[cnt][i] = prev
                            prev = arr2[j][i]
                        cnt-=1
            if prev != 0:
                arr2[cnt][i] = prev
                cnt-=1
            for j in range(cnt,-1,-1):
                arr2[j][i] = 0

result=0
for a in range(4):
    for b in range(4):
        for c in range(4):
            for d in range(4):
                for e in range(4):
                    arr2=deepcopy(arr)
                    movingArr(a)
                    movingArr(b)
                    movingArr(c)
                    movingArr(d)
                    movingArr(e)
                    for i in range(N):
                        for j in range(N):
                            if result<arr2[i][j]:
                                result=arr2[i][j]

print(result)