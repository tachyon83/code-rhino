import sys
sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline())
plumb = list(map(int, sys.stdin.readline().split()))

curr = 1
plumb.sort()
for i in range(n):
  if curr < plumb[i]:
    break
  curr += plumb[i]
print(curr)
