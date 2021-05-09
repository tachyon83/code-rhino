from sys import stdin
import sys

input = stdin.readline

N, M = map(int, input().split())

for _ in range(N):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

for _ in range(M):
    U, V, C = map(int, sys.stdin.readline().split())
