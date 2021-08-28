import sys
input=sys.stdin.readline

bitmask=[0]
for i in range(20):
    bitmask.append(1<<i)
S=0
full=((1<<20)-1)
def calc(operation,num):
    global S
    if operation=='add':
        S=S|bitmask[num]
    elif operation=='remove':
        S=S&(~bitmask[num])
    elif operation=='check':
        if S&bitmask[num]:
            print(1)
        else:
            print(0)
    elif operation=='toggle':
        S=S^bitmask[num]
    elif operation=='all':
        S=S|full
    elif operation=='empty':
        S=0

M=int(input())

for _ in range(M):
    a=input().split()
    if len(a)==2:
        calc(a[0],int(a[1]))
    else:
        calc(a[0],0)
