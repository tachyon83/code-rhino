class Solution:
    def constructDistancedSequence(self, n: int):
        
        N = n * 2 - 1
        arr = [0] * N
        self.answer = None
        
        def backtrack(idx, remain):
            if self.answer: return
            if idx == N:
                self.answer = arr.copy()
                return
            if arr[idx]:
                backtrack(idx + 1, remain)
                return
            
            for num in sorted(remain, reverse = True):
                if num != 1 and idx + num >= N:
                    continue
                if num != 1 and arr[idx + num]:
                    continue
                arr[idx] = num
                if num != 1:
                    arr[idx + num] = num
                backtrack(idx + 1, remain - {num})
                arr[idx] = 0
                if num != 1:
                    arr[idx + num] = 0
        
        backtrack(0, set(range(1, n + 1)))
        return self.answer