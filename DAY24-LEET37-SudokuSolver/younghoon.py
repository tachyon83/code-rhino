class Solution:       
    def find_empty(self, board):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == '.':
                    return (i,j) #row, column
        return None
    
    def is_valid(self, board, number, position): #position : (i, j)
        # check column
        for i in range(len(board)): 
            if board[i][position[1]] == number and position[0] != i:
                return False
        # check row
        for j in range(len(board[0])):
            if board[position[0]][j] == number and position[1] != j:
                return False
        # check box
        box_x = position[1] // 3
        box_y = position[0] // 3
        
        for i in range(box_y * 3, box_y * 3 + 3):
            for j in range(box_x * 3, box_x * 3 + 3):
                if board[i][j] == number and (i,j) != position:
                    return False
        return True
    
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        find = self.find_empty(board)
        if not find:
            return True
        else:
            row, col = find
        
        for i in map(str, range(1, 10)):
            if self.is_valid(board, i, (row, col)):
                board[row][col] = i
                if self.solveSudoku(board):
                    return True
                else:
                    board[row][col] = '.'
        return False
