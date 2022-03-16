from collections import defaultdict

class Solution:
    def __init__(self):
        self.N = 9
        self.rows = defaultdict(set)
        self.cols = defaultdict(set)
        self.boxes = defaultdict(set)
        self.nums = set(map(str, range(1, 10)))
        # func
        self.get_box_no = lambda r, c: r // 3 + 3 * (c // 3) 
        
    def solveSudoku(self, board):
        # init data
        for idx in range(self.N**2):
            c, r  = divmod(idx, self.N)
            ch = board[c][r]
            if ch.isdigit():
                self.rows[c].add(ch)
                self.cols[r].add(ch)
                self.boxes[self.get_box_no(r, c)].add(ch)
        # get answer
        self.check(0, board)
        return board
        
    def check(self, idx, board):
        c, r = divmod(idx, self.N)
        
        if idx == 81:
            return True
        if board[c][r] != '.':
            return self.check(idx + 1, board)
        
        for num in self.nums:
            if any([
                num in self.rows[c], 
                num in self.cols[r],
                num in self.boxes[self.get_box_no(r, c)]]):
                continue
                
            
            board[c][r] = num
            self.rows[c].add(num)
            self.cols[r].add(num)
            self.boxes[self.get_box_no(r, c)].add(num)
            
            if self.check(idx + 1, board):
                return True

            board[c][r] = '.'
            self.rows[c].remove(num)
            self.cols[r].remove(num)
            self.boxes[self.get_box_no(r, c)].remove(num)
                
        return False
