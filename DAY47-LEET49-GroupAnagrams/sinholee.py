class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = dict()
        for s in strs:
            visited = [0] * 26 
            for c in s:
                num = ord(c) - ord('a')
                visited[num] += 1
            temp = " ".join(map(str,visited))
            if dic.get(temp) is not None:
                dic[temp].append(s)
            else:
                dic[temp]=[s]
        return [v for k, v in dic.items()]
solution = Solution()

print(solution.groupAnagrams(["bdddddddddd", "bbbbbbbbbbc"]))
