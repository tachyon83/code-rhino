import sys
input=sys.stdin.readline

N,r,c=map(int,input().split())
global result
result=0

def isRange(y,x,blockSize):
    if y<=r<y+blockSize and x<=c<x+blockSize:
        return True
    return False


def divBlock(y,x,blockSize):
    global result
    if y==r and x == c:
        print(result)
        return
    
    if isRange(y,x,blockSize):
        size=blockSize//2
        divBlock(y,x,size)
        divBlock(y,x+size,size)
        divBlock(y+size,x,size)
        divBlock(y+size,x+size,size)
    else:
        result+=blockSize**2

divBlock(0,0,1<<N)