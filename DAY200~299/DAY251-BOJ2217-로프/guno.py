import sys
input=sys.stdin.readline

n=int(input())
weights=[int(input()) for _ in range(n)]

print(max( w*(n-i) for i,w in enumerate(sorted(weights))  ))
