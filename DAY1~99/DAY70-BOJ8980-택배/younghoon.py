import sys
# sys.stdin = open('input.txt', 'r')

n,c = map(int, sys.stdin.readline().split())
box = []
for _ in range(int(sys.stdin.readline())):
  box.append(list(map(int, sys.stdin.readline().split())))
box.sort(key=lambda x:x[1])
result = 0
weight = [0] * (n+1)
print(box)
for start, end, w in box:
  left = c - max(weight[start:end])
  add = None
  if w <= left:
    add = w
  else:
    add = left
  result += add
  for i in range(start, end):
    weight[i] += add
print(result)



