class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        INF = 0x7FFFFFFF
        prices = collections.defaultdict(lambda: collections.defaultdict(int))
        for s, t, p in flights:
            prices[s][t] = p
        ans = prices[src][dst] or INF
        queue = [src]
        costs = {src : 0}
        for x in range(K + 1):
            nset = set()
            for loc in queue:
                ans = min(ans, costs[loc] + (prices[loc][dst] or INF))
                for next in prices[loc]:
                    costs[next] = min(costs.get(next, INF), costs[loc] + (prices[loc][next] or INF))
                    nset.add(next)
            queue = list(nset)
        return ans if ans < INF else -1
