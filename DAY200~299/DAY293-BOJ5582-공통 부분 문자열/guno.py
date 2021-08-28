import sys
input=sys.stdin.readline
a=input()[:-1];l=len(a)
b=input()[:-1];m=len(b)
d=[0]*(m+1)
answer=0
for i in range(l):
  d1=[0]
  for j in range(m):
    if a[i]==b[j]:
      d1.append(d[j]+1)
    else:
      d1.append(0)
  answer=max(answer,max(d1))
  d=d1[:]
print(answer)
