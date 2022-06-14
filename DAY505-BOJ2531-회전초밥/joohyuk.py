import sys
si=sys.stdin.readline

n,d,k,c=[int(e) for e in si().split()]
plates,hold,s,mx=[],dict(),0,0
for _ in range(n):plates.append(int(si()))

def add(value):
    global hold
    if value not in hold:hold[value]=0
    hold[value]+=1

def remove(value):
    global hold
    hold[value]-=1
    if not hold[value]:hold.pop(value)

for i in range(k):add(plates[i])
while s<n:
    mx=max(mx,len(hold.keys()))
    temp=len(hold.keys())
    if c not in set(hold.keys()):temp+=1
    mx=max(mx,temp)
    remove(plates[s])
    add(plates[(s+k)%n])
    s+=1

print(mx)
