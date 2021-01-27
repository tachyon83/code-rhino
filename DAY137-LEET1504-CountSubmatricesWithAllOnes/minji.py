class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        
        h, w = len(mat), len(mat[0])
        dp = [[ 0 for _ in range(w)] for _ in range(h)]
        
        for y in range(h):
            for x in range(w):
                if x == 0:
                    dp[y][x] = mat[y][x]    
                else:
                    if mat[y][x] == 1:
                        dp[y][x] = dp[y][x-1] + 1
        count = 0
        for y in range(h):
            for x in range(w):
                min_w = dp[y][x]
                for h_idx in range(y, -1, -1):
                    min_w = min(min_w, dp[h_idx][x])
                    count += min_w
                    if min_w == 0:
                        break
        return count
