class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0
        
        candies = [1]
        for i in range(len(ratings) - 1):
            if ratings[i] < ratings[i + 1]:
                candies.append(candies[-1] + 1)
            else:
                candies.append(1)
        for i in reversed(range(len(ratings) - 1)):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
        return sum(candies)
