N = int(input())
time = [0] * (N+1)
pre = [0] * (N+1)
jobs = [0] * (N+1)

for i in range(1, N+1):
    info = list(map(int, input().split()))
    time[i] = info[0]
    pre[i] = info[2:]
    
for i in range(1, N+1):
    if not pre[i]:
        jobs[i] = time[i]
        continue
    for j in pre[i]:
        jobs[i] = max(jobs[i], jobs[j]+time[i])
print(max(jobs))
