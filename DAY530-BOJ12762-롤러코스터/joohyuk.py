import sys,copy
si=sys.stdin.readline

n,mx=int(si()),0
p=[int(e) for e in si().split()]
dp=[[[0 for _ in range(max(p)+2)] for _ in range(4)]for _ in range(2)]
dp[0][0][p[0]]=1
dp[0][1][max(p)+1]=0
dp[0][2][p[0]]=1
dp[0][3][0]=0
base=[[0 for _ in range(max(p)+2)] for _ in range(4)]

for i in range(1,n):
  for j in range(p[i]+1,max(p)+2):
    dp[1][0][p[i]]=max(dp[1][0][p[i]],dp[0][0][j]+1)
    dp[1][0][p[i]]=max(dp[1][0][p[i]],dp[0][1][j]+1)
  for j in range(1,max(p)+2):
    dp[1][1][j]=max(dp[0][0][j],dp[0][1][j])
    dp[1][3][j]=max(dp[0][2][j],dp[0][3][j])
  for j in range(p[i]):
    dp[1][2][p[i]]=max(dp[1][2][p[i]],max(dp[0][0][j],dp[0][1][j],dp[0][2][j],dp[0][3][j])+1)
  
  dp[0]=copy.deepcopy(dp[1])
  dp[1]=copy.deepcopy(base)

for i in range(4):mx=max(mx,max(dp[0][i]))

print(mx)
