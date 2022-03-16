#나중에 다시하는걸로!

import sys
sys.stdin = open('input.txt', 'r')
N = int(sys.stdin.readline())

def to_n_base(num,base):
  if num < base:
    return [num]
  return to_n_base(num//base,base) + [num % base]

for i in range(2,int(N**0.5)+2):
  converted = to_n_base(N, i)
  if converted == converted[::-1]:
    print(i)
