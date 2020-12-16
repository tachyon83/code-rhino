'''
시간이 부족해서 공부하고 있던 코드 올립니다ㅠㅠ
'''

import sys
input = sys.stdin.readline

n = int(input())
times = [0] * (n+1)
graph = {}
for i in range(1, n+1):
    lst = list(map(int, input().split()))
    times[i] = lst[0]
    if lst[1] == 0:
        continue
    for j in lst[2:]:
        if i in graph:
            graph[i].append(j)
        else:
            graph[i] = [j]
            
for i in range(1, n+1):
    if i in graph:
        time = 0
        for j in graph[i]:
            time = max(time, times[j])
        times[i] += time
        
print(max(times))
