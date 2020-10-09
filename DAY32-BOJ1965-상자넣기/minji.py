# -*- coding: utf-8 -*-

"""
상자의 크기가 뒤에 있는 크기보다 작으면  앞의 상자를 뒤에 있는 상자 안에 넣을 수 있다.


1 6 2 5 7 3 5 6

1 2 2 3 4 3 4 5
"""
import sys

def sol():
    memo.append(1)
    for i in range(1, n):
        t = []
        for j in range(i):
            if boxes[i] > boxes[j]:
                t.append(memo[j]+1)
        if not t:
            memo.append(1)
        else:
            memo.append(max(t))
    print(max(memo))

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    memo = []
    boxes = list(map(int, sys.stdin.readline().split()))

    sol()
