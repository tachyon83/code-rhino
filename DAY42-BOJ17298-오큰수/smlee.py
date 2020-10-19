N = int(input())
nge = list(map(int, input().split()))
stack = []
result = [-1 for _ in range(N)]

for i in range(len(nge)):
    try:
        while nge[stack[-1]] < nge[i]:
            result[stack.pop()] = nge[i]
    except:
        pass        
    stack.append(i)        
for i in range(N):
    print(result[i], end = ' ')
