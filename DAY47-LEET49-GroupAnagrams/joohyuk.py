class Solution:
    def groupAnagrams(self, strs: List[str]):
        worddict=dict()
        for st in strs:
            sttuple=tuple(sorted([e for e in st]))
            stset=set(sttuple)
            if sttuple not in worddict:
                worddict[sttuple]=[]
            worddict[sttuple].append(st)
        ans=[]
        for e in worddict:
            ans.append(worddict[e])
        return ans
            
            
        
