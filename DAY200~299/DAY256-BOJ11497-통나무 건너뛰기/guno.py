import sys
input=sys.stdin.readline
T=int(input())
for __ in range(T):
    N=int(input())
    trees=list(map(int,input().split()))
    trees.sort()
    newTrees=[0]*N
    l,r=0,0
    for i in range(N):
        if not i%2:
            newTrees[i//2]=trees[i]
        else:
            newTrees[N-i//2-1]=trees[i]
    
    print(max(abs(newTrees[i]-newTrees[i-1])for i in range(N)))
