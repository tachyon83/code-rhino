input = __import__('sys').stdin.readline

N = int(input())
ans = 0
times = [0] * (N + 1)

for i in range(1, N + 1):
    time, *indegree = map(int, input().split())
    times[i] = time
    if len(indegree) > 1:
        times[i] = time + max(map(lambda x: times[x], indegree[1:]))
    
    ans = max(ans, times[i])

print(ans)   
