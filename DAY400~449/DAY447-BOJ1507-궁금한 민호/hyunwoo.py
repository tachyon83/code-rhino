# 플로이드-워셜 알고리즘 응용문제
# 플로이드-워셜 알고리즘을 이미 한 번 거쳐 나온 결과를 역순으로 생각하는 문제

import sys
from copy import deepcopy

n = int(sys.stdin.readline())
li = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
# dp = 주어진 인접행렬 그래프에서 필요없는 경로를 빼낼 인접행렬
dp = deepcopy(li)

for k in range(n):
    for i in range(n):
        for j in range(n):
            # i, j, k 셋 중 어느 두 개라도 같을 시 무시함
            if i == j or j == k or k == i:
                continue
            # 만약 li[i][j] == li[i][k] + li[k][j]라면, i -> j로 가는 경로는 i -> k -> j로 가는 경로로 대체 가능하므로
            # dp[i][j] 경로를 배제할 수 있음
            if li[i][j] == li[i][k] + li[k][j]:
                dp[i][j] = 0
            # 탐색 도중 i -> j로 가는 경로보다 i -> k -> j로 가는 경우가 더 짧은 경로가 나올 경우, 
            # 문제 조건과 모순이므로 -1 출력 후 프로그램 종료
            elif li[i][j] > li[i][k] + li[k][j]:
                print(-1)
                exit(0)

# 탐색 후 얻어진 dp의 모든 요소를 합할 경우 중복이 발생하므로 (i -> j로 가는 경우 + j -> i로 가는 경우)
# 이를 2로 나누면 전체 경로의 합이 나옴
print(sum([sum(dp[x]) for x in range(n)]) // 2)
