import sys
#sys.stdin = open("input.txt", "r")
stack = []
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

result = [-1 for _ in range(N)]

for i in range(N):
    while stack and arr[stack[-1]]<arr[i]:
        result[stack.pop()] = arr[i]
    stack.append(i)
print(*result)
