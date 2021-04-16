class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        i = 0
        j = len(tokens) - 1
        answer = 0
        while i <= j:
            if P >= tokens[i]:
                answer += 1
                P -= tokens[i]
                i += 1
            else:
                if i == j:
                    break
                answer -= 1
                if answer < 0: return 0
                P += tokens[j]
                j -= 1
        return answer