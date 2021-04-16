class Solution:
    def solveSudoku(self, board):
        digits   = {*'123456789'}
        cols     = [{*digits} for _ in range(9)]
        rows     = [{*digits} for _ in range(9)]
        boxes    = [{*digits} for _ in range(9)]
        to_visit = {*()}

        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val == '.':
                    to_visit.add((i, j))
                else:
                    row, col, box = rows[i], cols[j], boxes[i//3*3 + j//3]
                    row.discard(val)
                    col.discard(val)
                    box.discard(val)

        def solve():
            if not to_visit:
                return True
            x = y = minfree = choices = 10
            for i, j in to_visit:
                row, col, box = rows[i], cols[j], boxes[i//3*3 + j//3]
                free = col & row & box
                if len(free) < minfree:
                    if len(free) == 0:
                        return False
                    x, y = j, i
                    xrow = row
                    xcol = col
                    xbox = box
                    choices = free
                    minfree = len(free)

            to_visit.discard((y, x))
            for choice in choices:
                board[y][x] = choice
                xcol.discard(choice)
                xrow.discard(choice)
                xbox.discard(choice)
                if solve():
                    return True
                xcol.add(choice)
                xrow.add(choice)
                xbox.add(choice)
            to_visit.add((y, x))
            return False

        solve()

board = []
for _ in range(9):
    row = input().split()
    row = ['.' if i == '0' else i for i in row]
    board.append(row)

s = Solution()
s.solveSudoku(board)

for row in board:
    for i in row:
        print(i, end=' ')
    print()