from sys import stdin
import sys

input = stdin.readline

N, M = map(int, input().split())

for _ in range(N):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for _ in range(M):
    U, V, C = map(int, input().split())
