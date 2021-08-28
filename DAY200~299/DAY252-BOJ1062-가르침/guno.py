import sys
from itertools import combinations
input=sys.stdin.readline

n,k=map(int,input().split())
words=[input()[4:-4] for _ in range(n)]
rest=[i for i in range(26) if i not in [0,2,8,13,19] ]
max_cnt=0

def stringToBit(s):
    temp=0
    for c in s:
        if ord(c)-97 not in [0,2,8,13,19]:
            temp|=1<<ord(c)-97
    return temp
words=[stringToBit(word) for word in words]

if k<5:
    print(0)
else:
    for comb in combinations([1<<i for i in rest],k-5):
        cnt=0
        nowChar=sum(comb)
        for word in words:
            if word&nowChar==word:
                cnt+=1
        max_cnt=max(max_cnt,cnt)
    print(max_cnt)
