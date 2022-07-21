import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    while scoville[0]<K:
        if len(scoville)<2:return -1
        a=heapq.heappop(scoville)
        b=heapq.heappop(scoville)
        answer+=1
        heapq.heappush(scoville,a+b*2)
    return answer
