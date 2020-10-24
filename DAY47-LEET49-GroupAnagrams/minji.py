from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs):
        ans = defaultdict(list)
        for s in strs:
            cnt = [0] * 26
            for c in s:
                cnt[ord(c) - ord('a')] += 1
            ans[tuple(cnt)].append(s)
        return ans.values()
