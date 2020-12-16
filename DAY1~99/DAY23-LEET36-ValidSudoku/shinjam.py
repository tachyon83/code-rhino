from collections import defaultdict

class Solution:
    def __init__(self):
        self.N = 9
        self.rows = defaultdict(set)
        self.cols = defaultdict(set)
        self.boxes = defaultdict(set)
        # func
        self.box_no = lambda r, c: r // 3 + 3 * (c // 3) 
        
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for idx in range(self.N**2):
            c, r = divmod(idx, self.N)
            ch = board[c][r]
            if not ch.isdigit():
                continue
            if any([
                ch in self.rows[c],
                ch in self.cols[r],
                ch in self.boxes[self.box_no(r, c)]
            ]):
                return False
            self.rows[c].add(ch)
            self.cols[r].add(ch)
            self.boxes[self.box_no(r, c)].add(ch)
        return True
