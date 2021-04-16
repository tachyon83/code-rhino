import sys
from collections import deque
si = sys.stdin.readline

def rotate(s,d):
    if d>0:
        return s[-1]+s[:-1]
    return s[1:]+s[0]

def sumup():
    global gears
    ret=0
    for s in gears:
        ret+=int(s[0])
    return ret

gears,q,vis,dg=[[]],deque(),[False for _ in range(4+1)],[-1,1]
for _ in range(4):
    gears.append(si()[:-1])
k,p=int(si()),0
while k:
    k-=1
    n,d=[int(e) for e in si().split()]
    vis[n]=True
    q.append([n,d])

    while q:
        cg,cdr=q.popleft()
        if cdr==1:ndr=-1
        else: ndr=1
        for i in range(2):
            ng=cg+dg[i]
            if 0<ng<5 and not vis[ng]:
                if i:
                    if gears[cg][2]!=gears[ng][6]:
                        vis[ng]=True
                        q.append([ng,ndr])
                else:
                    if gears[cg][6]!=gears[ng][2]:
                        vis[ng]=True
                        q.append([ng,ndr])
                    




