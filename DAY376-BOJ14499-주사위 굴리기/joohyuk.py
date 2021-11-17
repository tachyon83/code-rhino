import sys
si=sys.stdin.readline

n, m, x, y, k = [int(e) for e in si().split()]
board=[]
for _ in range(n):board.append([int(e) for e in si().split()])
orders=[int(e)-1 for e in si().split()]
dr,dc=[0,0,-1,1],[1,-1,0,0]
dice,hold=[],[]
for _ in range(6):
  dice.append(0)
  hold.append(0)
dir=[[2,0,5,3,4,1],[1,5,0,3,4,2],[4,1,2,0,5,3],[3,1,2,5,0,4]]
for order in orders:             
  x,y=x+dr[order],y+dc[order]
  if x<0 or x>=n or y<0 or y>=m:
    x,y=x-dx[order],y-dy[order]
    continue
  for i in range(6):hold[i]=dice[i]
  for i in range(6):dice[i]=hold[dir[order][i]]
  if board[x][y]:
    dice[5]=board[x][y]
    board[x][y]=0
  else:board[x][y]=dice[5]
  
  print(dice[0])
