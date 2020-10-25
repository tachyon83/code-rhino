from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_dict = defaultdict(list)
        
        for word in sorted(strs):
            str_dict[tuple(sorted(word))].append(word)
        ret = sorted(str_dict.values(), key=lambda x: len(x))
        return ret
