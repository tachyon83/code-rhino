import sys
 
def sol():
   cnt = []
   for i in range(n-7):
      for j in range(m-7):
         cnt_w, cnt_b = 0, 0
         for y in range(i, i+8):
            for x in range(j, j+8):
               if (x+y) % 2 == 0:
                  if maps[y][x] != 'W':
                     cnt_w += 1
                  if maps[y][x] != 'B':
                     cnt_b += 1
               else:
                  if maps[y][x] != 'B':
                     cnt_w += 1
                  if maps[y][x] != 'W':
                     cnt_b += 1
         cnt.append(cnt_w)
         cnt.append(cnt_b)
   return min(cnt)
 
if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split())) #row, col
    maps = [list(map(str, sys.stdin.readline())) for _ in range(n)]
 
    print(sol())
