import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

stack = []
ret = [-1] * N
for idx, val in enumerate(reversed(A)):
    while stack and stack[-1] <= val:
        stack.pop()
    if stack:
        ret[N-idx-1] = stack[-1]
    stack.append(val)
    
print(*ret)            
        
