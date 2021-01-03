class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        left, right = 0, len(tokens)-1
        score = 0
        result = 0

        while left <= right:
            if P >= tokens[left]:
                P -= tokens[left]
                left += 1
                score += 1
                result = max(result, score)
            elif score > 0:
                score -= 1
                P += tokens[right]
                right -=1
            else:
                break
                
        return result
        
