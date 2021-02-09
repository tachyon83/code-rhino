class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        lo = max(weights)
        hi = sum(weights)
        while lo <= hi:
            mid = (lo + hi) // 2
            days = 1
            temp = 0
            fail = False
            for i in weights:
                if temp + i <= mid:
                    temp += i
                else:
                    temp = i
                    days += 1
                    if days > D:
                        fail = True
                        break
            if fail:
                lo = mid + 1
            else:
                hi = mid - 1
        return lo