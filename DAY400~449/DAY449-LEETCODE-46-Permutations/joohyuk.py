from itertools import permutations as pm

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        a,ans=pm(nums,len(nums)),[]
        for e in a:ans.append(list(e))
        return ans
        
        
