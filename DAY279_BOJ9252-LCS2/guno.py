import sys
import copy
input=sys.stdin.readline

s1,s2=input().rstrip(),input().rstrip()
l1,l2,INF=len(s1),len(s2),10000
idxs=[[]for _ in range(26)]

for i in range(l2-1,-1,-1):
    idxs[ord(s2[i])-65].append(i)
dp=[[-1]]+[[INF]for _ in range(l1)]#

for maxL,c in enumerate(s1):
    for i in idxs[ord(c)-65]:
        for length in range(1,maxL+2):
            if dp[length][-1]>i:
                if dp[length-1][-1]<i:
                    temp=copy.deepcopy(dp[length-1])
                    temp.append(i)
                    dp[length]=temp
                break
    

answer=len(dp)-1
while dp[answer][-1]==INF and answer>0:
    answer-=1

print(answer)
if answer:
    print(''.join(s2[i] for i in dp[answer][1:]))
