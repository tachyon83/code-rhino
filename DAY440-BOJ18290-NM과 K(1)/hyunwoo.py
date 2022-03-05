'''
백트래킹 문제. N과 M 시리즈와 풀이 로직은 비슷하나 파이썬 기준 그대로 구현하면 TLE가 떠서
백트래킹 탐색 경우의 수를 줄이는 궁리가 필요함
'''

import sys

max_sum = -sys.maxsize
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
loopexit = False

# [x, y] 지점부터 순차적으로 탐색
def backtrack(x, y):
    global max_sum
    
    # k번 방문 시 최대값 갱신
    if len(visited) == k:
        temp = 0
        for point in visited:
            temp += li[point[0]][point[1]]
        max_sum = max(max_sum, temp)
        return
    
    for i in range(x, n):
        for j in range(m):
            # [x, y]보다 작을 시 탐색 X
            if i == x and j < y:
                continue
            
            # [i, j]나 그 인접칸을 이미 방문했을 시 탐색 X
            loopexit = False
            if chk[i][j]:
                continue
            for dir in range(4):
                nx = i + dx[dir]
                ny = j + dy[dir]
                if 0 <= nx < n and 0 <= ny < m:
                    if chk[nx][ny]:
                        loopexit = True
            if loopexit:
                continue
            
            # [i, j] 다음 칸을 재귀적으로 방문
            chk[i][j] = True
            visited.append([i, j])
            if j == m-1:
                backtrack(i+1, 0)
            else:
                backtrack(i, j+1)
            visited.pop()
            chk[i][j] = False

n, m, k = map(int, sys.stdin.readline().split())
li = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

chk = [[False for _ in range(m)] for __ in range(n)]
visited = []

backtrack(0, 0)

print(max_sum)
