from collections import defaultdict
import heapq


class Solution:
    def findCheapestPrice(self, n: int, flights, src: int, dst: int, K: int) -> int:
        graph = defaultdict(dict)
        for st, ed, cost in flights:
            graph[st][ed] = cost
        
        cost_memo = {i:float('inf') for i in range(n)}
        stop_memo = {i:float('inf') for i in range(n)}
        heap = [(0, 0, src)] # cost, stop, curr
        
        while heap:
            cost, stop, curr = heapq.heappop(heap)
            if curr == dst:
                return cost
            if stop > K:
                continue
            for nxt in graph[curr]:
                if cost + graph[curr][nxt] < cost_memo[nxt]:
                    cost_memo[nxt] = cost + graph[curr][nxt]
                    heapq.heappush(heap, (cost + graph[curr][nxt], stop + 1, nxt))
                elif stop + 1 < stop_memo[nxt]:
                    stop_memo[nxt] = stop + 1
                    heapq.heappush(heap, (cost + graph[curr][nxt], stop + 1, nxt))
        return -1 if cost_memo[dst] == float('inf') else cost