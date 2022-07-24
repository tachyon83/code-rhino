import sys
si=sys.stdin.readline
sys.setrecursionlimit(int(1e5)+5)

n,mod=int(si()),int(1e9+7)
nums=[0]+[int(e) for e in si().split()]
g,tree=[[]for _ in range(n+1)],[[] for _ in range(n+1)]

for _ in range(n-1):
  a,b=[int(e) for e in si().split()]
  g[a].append(b)
  g[b].append(a)

def traverse(n,p):
  tree[p].append(n)
  for nx in g[n]:
    if nx==p:continue
    traverse(nx,n)

traverse(1,0)

dp=[[[-1 for _ in range(10)] for _ in range(2)]for _ in range(n+1)]

def solve(curr,v, pick):
  if pick and nums[curr]<v:return 0

  value=nums[curr] if pick else v
  if dp[curr][pick][value]!=-1:return dp[curr][pick][value]
  dp[curr][pick][value]=0

  for nx in tree[curr]:
    dp[curr][pick][value]+=solve(nx,value,0)
    dp[curr][pick][value]+=solve(nx,value,1)
    
  dp[curr][pick][value]+=pick
  dp[curr][pick][value]%=mod
  return dp[curr][pick][value]

print((solve(1,0,0)+solve(1,0,1))%mod)
