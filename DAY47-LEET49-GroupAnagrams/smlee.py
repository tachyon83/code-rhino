strs = ["eat","tea","tan","ate","nat","bat"]

class Solution:
    def groupAnagrams(self, strs) :
      dic = {}
      for i in range(len(strs)):
        word = ''.join(sorted(strs[i]))
        if word not in dic :
          dic[word] = [strs[i]]
        else :
          dic[word].append(strs[i])
      return print(dic.values())

a = Solution()
a.groupAnagrams(strs)
