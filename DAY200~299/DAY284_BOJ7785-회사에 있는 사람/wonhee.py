import sys
input=sys.stdin.readline

N= int(input())
s={}
for _ in range(N):
    name,command=input().split()
    if command=='enter':
        s[name]=1
    elif command=='leave':
        s[name]=0

name_list=[]
for name in s.keys():
    if s[name]==1:
        name_list.append(name)
name_list.sort(reverse=True)

for name in name_list:
    print(name)