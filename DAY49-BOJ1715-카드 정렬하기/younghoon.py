'''
list 에서 heappop을 하면 이상한 결과값이 나오기도 한다
항상 heappush를 해주거나 list를 heapify해주자
'''


import sys
import heapq
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline())
card_list = []
for _ in range(N):
    heapq.heappush(card_list, int(sys.stdin.readline()))

if len(card_list) == 1:
    print(0)
else:
    answer = 0
    while len(card_list) > 1:
        first = heapq.heappop(card_list)
        second = heapq.heappop(card_list)
        answer += first + second
        heapq.heappush(card_list, first + second)
    print(answer)
