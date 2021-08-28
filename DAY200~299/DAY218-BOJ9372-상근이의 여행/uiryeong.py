import sys

def solution():
    T = int(input())
    for _ in range(T):
        N, M = map(int, sys.stdin.readline().split())
        print(N-1)
        for _ in range(M):
            A, B = map(int, sys.stdin.readline().split())
solution()
