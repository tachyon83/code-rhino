import sys
n=int(sys.stdin.readline())
video=[list(map(int,sys.stdin.readline().strip())) for _ in range(n)]#x행 y열
 
def compression(x,y,n):
    check=video[x][y]
    for i in range(x,x+n):
        for j in range(y,y+n):
            if check!=video[i][j]:#하나라도 다르면
                #4등분
                print('(', end='')
                compression(x,y,n//2)#1사분면
                compression(x,y+n//2,n//2) #2사분면
                compression(x+n//2,y,n//2)  #3사분면
                compression(x+n//2,y+n//2,n//2)#4사분면
                print(')', end='')
                return
 
 
    if check==0:#모두 0일때
        print('0',end='')
        return
    else:   #모두 1일때
        print('1',end='')
        return
 
 
compression(0,0,n)
 
