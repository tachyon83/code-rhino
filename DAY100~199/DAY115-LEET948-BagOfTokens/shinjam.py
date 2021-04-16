from collections import deque
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        ans, score = 0, 0
        queue = deque(sorted(tokens))
        while queue:
            if queue[0] <= P:
                P -= queue.popleft()
                score += 1
            elif score:
                P += queue.pop()
                score -= 1
            else:
                break
            if ans < score:
                ans = score
            
        return ans
