import heapq
def solution(op):
    heap = []
    for w in op:
        c, n = w.split()
        n = int(n)
        if c=='I':
            heapq.heappush(heap, n)
        else:
            try:
                if n==-1:
                    heapq.heappop(heap)
                else:
                    heap = [-i for i in heap]
                    heapq.heapify(heap)

                    heapq.heappop(heap)

                    heap = [-i for i in heap]
                    heapq.heapify(heap)
            except:
                pass
    if heap:
        return [max(heap),min(heap)]
    else:
        return [0,0]