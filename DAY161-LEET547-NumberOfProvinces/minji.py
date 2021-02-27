class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(s):
            visited.add(s)
            for e in range(len(isConnected)):
                if isConnected[s][e] and e not in visited:
                    dfs(e)
        
        ans = 0
        visited = set()
        
        for s in range(len(isConnected)):
            if s not in visited:
                ans += 1
                dfs(s)
        
        return ans
