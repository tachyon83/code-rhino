import sys,math
si=sys.stdin.readline

n,orders,dp,big,pos=int(si()),[],[],math.inf,[]
suna=[int(e) for e in si().split()]
for _ in range(n):orders.append([int(e) for e in si().split()])
dr,dc,ret=[0,1,0,-1,0],[0,0,-1,0,1],big

def dist(c1,c2):return abs(c1[0]-c2[0])+abs(c1[1]-c2[1])

for order in orders:
    hold=[]
    for i in range(5):hold.append([order[0]+dr[i],order[1]+dc[i]])
    pos.append(hold)
    dp.append([big for _ in range(5)])

for i in range(5):dp[0][i]=dist(suna,pos[0][i])

for k in range(1,len(orders)):
    for i in range(5):
        for j in range(5):
            dp[k][j]=min(dp[k][j],dp[k-1][i]+dist(pos[k-1][i],pos[k][j]))

for v in dp[n-1]:ret=min(ret,v)
print(ret)
