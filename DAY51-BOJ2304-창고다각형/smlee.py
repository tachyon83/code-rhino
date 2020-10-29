import sys

N = int(sys.stdin.readline())
cont = [0] * 1001
i = 0 
j = len(cont)-1
imax = 0
jmax = 0
result = 0

for _ in range(N):
  L, H = list(map(int, sys.stdin.readline().split()))
  cont[L] = H

while i <= j:
  if cont[i] < cont[j]:
    imax = max(imax, cont[i])
    result += (imax)
    i += 1
  else:
    jmax = max(jmax, cont[j])
    result += (jmax)
    j -= 1

print(result)

