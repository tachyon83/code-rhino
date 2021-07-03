import sys
input=sys.stdin.readline

s,k=input().split()
l=len(s)
k=int(k)
kmp=[0]*l

j=0
for i in range(1,l):
    while  j>0 and s[j]!=s[i]:
        j=kmp[j-1]
    if s[j]==s[i]:
        j+=1
        kmp[i]=j

print(l+(l-kmp[-1])*(k-1))
