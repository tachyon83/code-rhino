class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ana = collections.defaultdict(list)
        for word in strs:
            ana[''.join(sorted(word))].append(word)
        return ana.values()
