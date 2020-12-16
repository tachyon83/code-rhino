
from sys import stdin
from collections import defaultdict
from collections import deque

stdin = open("input.txt", "r")

# N: 가수의 수
# M: 보조 PD의 수
N, M = map(int, stdin.readline().split())

ind = [0 for _ in range(N+1)] # 진입 차수
path = defaultdict(lambda: []) # 다음 방문

# 입력 받으며 진입 차수와 다음 방문 업데이트
for _ in range(M):
    singers = list(map(int, stdin.readline().split()))[1:] # 0 번째는 숫자이므로
    for i in range(len(singers) - 1): 
        path[singers[i]].append(singers[i+1])
        ind[singers[i+1]] += 1

# 진입 차수가 0인 지점들 먼저 넣기        
queue = deque()
for i in range(1, N+1):
    if ind[i] == 0: queue.append(i)

# 위상 정렬
# queue를 이용해 pop하며 다음 방문의 진입차수를 줄이며 업데이트
answer = []
while queue:
    s = queue.popleft()
    answer.append(s)

    # 진입 차수 업데이트
    for i in path[s]:
        ind[i] -= 1
        if ind[i] == 0:
            queue.append(i)

# 못 갈 경우
if len(answer) != N:
    print(0)
else:
    for _ in answer:
        print(_)
