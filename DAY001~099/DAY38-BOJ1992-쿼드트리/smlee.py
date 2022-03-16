import sys

N = int(sys.stdin.readline())
quadTree = [list(map(int,sys.stdin.readline().strip())) for _ in range(N)]

def solution(x, y, N) :
  image = quadTree[x][y]
  for i in range(x, x+N) :
    for j in range(y, y+N) :
      if image != quadTree[i][j] :
        print('(', end='')
        solution(x,y,N//2)
        solution(x,y+N//2,N//2)
        solution(x+N//2,y,N//2)
        solution(x+N//2,y+N//2,N//2)
        print(')', end='')
        return     
  if image == 0 :
    print('0', end='')
  else :
    print('1', end='')
  

solution(0,0,N)
