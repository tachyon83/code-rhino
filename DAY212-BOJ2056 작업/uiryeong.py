import sys

input = sys.stdin.readline


N= int(input())
times = [0 for i in range(N+1)] 
graph ={i:[] for i in range(1, N+1} 

for work in range(1, N+1):
    work_info = list(map(int, input().split()))  
    times[i] = work_info[0] 
    if work_info[1] == 0:
        continue
	
    # 선행되야하는 작업이 있다면 
    for prework in work_info[2:]:
        graph[i].append(prework) 

for work in range(1, N+1): 
    time = 0
    for prework in graph[work]: 
        time = max(time, times[prework]) 
    times[work] += time 그 시간을 현재 작업시간에 더해준다.


print(max(times))
