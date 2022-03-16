import sys
from math import sqrt
si=sys.stdin.readline

cnt,lg=0,4
def solve(v,d,idx):
    global cnt,lg
    if d==lg:
        temp=sqrt(v)
        if not temp%1 and temp>=idx:cnt+=1
        return
    for i in range(idx,182+1):
        if i*i<v:solve(v-i*i,d+1,i)
        else:
            if i*i==v:cnt+=1
            return

n=1
while n:
    n,cnt=int(si()),0
    if not n:break
    solve(n,1,1)
    print(cnt)
