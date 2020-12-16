import heapq
import sys
si = sys.stdin.readline

n = int(si())
cards = []
while n:
    n -= 1
    cards.append(int(si()))
heapq.heapify(cards)
cnt = 0

if len(cards) == 1:
    print(0)
else:
    while len(cards) != 1:
        hold = 0
        hold += heapq.heappop(cards)
        hold += heapq.heappop(cards)
        cnt += hold
        heapq.heappush(cards, hold)
    print(cnt)
