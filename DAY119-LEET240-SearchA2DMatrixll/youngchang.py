class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            if row[-1] < target: continue
            if row[0] > target: break
            if row[bisect.bisect_left(row, target)] == target:
                return True
        return False