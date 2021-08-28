import sys
input=sys.stdin.readline
n,times,answer=int(input()),list(map(int,input().split())),0
times.sort()
for i in range(1,len(times)):
    times[i]+=times[i-1]

print(sum(times))
