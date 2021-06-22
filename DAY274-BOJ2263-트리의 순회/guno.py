import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
inorder=list(map(int,input().split()))
postorder=list(map(int,input().split()))
pos = [0]*(n+1) 
for i in range(n): 
    pos[inorder[i]] = i

answer=[]
def rec(a,b,c,d):
    global answer
    if a > b: return
    mid=postorder[d]
    answer.append(mid)
    
    i=pos[mid]
    leftLength=i-a
    rec(a,i-1,c,c+leftLength-1)#왼
    rec(i+1,b,c+leftLength,d-1)

rec(0,n-1,0,n-1)
for i in answer:
    print(i,end=" ")
