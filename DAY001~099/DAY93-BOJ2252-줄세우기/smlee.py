# 

import sys 
from collections import deque 

n, m = map(int, sys.stdin.readline().split()) 
inDegree = [0] * (n+1) 
inDegree[0] = -1 
direct = [[] for _ in range(n+1)] 
queue = deque()


for _ in range(m): 
  a, b = map(int, sys.stdin.readline().split())
  inDegree[b] += 1
  direct[a].append(b)

for i in range(1, n+1): 
  if inDegree[i] == 0: 
    queue.append(i)

while queue: 
  q = queue.popleft() 
  print(q, end=' ') 
  for d in direct[q]: 
    inDegree[d] -= 1 
    if inDegree[d] == 0: 
      queue.append(d)
