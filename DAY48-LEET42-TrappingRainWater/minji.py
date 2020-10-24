class Solution:
    def trap(self, height):
        n = len(height)

        if n == 0:
            return 0

        ans = 0
        l, r = [0] * n, [0] * n

        for i in range(1, n):
            l[i] = max(l[i - 1], height[i])

        for i in range(n - 2, 0, -1):
            r[i] = max(r[i + 1], height[i])


        for i in range(1, n - 1):
            ans += min(l[i], r[i]) - height[i]
        return ans

a = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(a.trap(height))
