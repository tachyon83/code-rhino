import sys
input=sys.stdin.readline

n=int(input())
exist={}
for _ in range(n):
    name,s=input().rstrip().split()
    if s[0]=='e':
        exist[name]=True
    else:
        exist[name]=False

names=[]
for name in exist:
    if exist[name]:
        names.append(name)

names.sort(reverse=True)
for name in names:
    print(name)
