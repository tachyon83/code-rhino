def solution(n):
    def backtrack(row = 0, hills = 0, next_row = 0, dales = 0, count = 0):
        if row == n:
            count += 1
        else:
            free_columns = columns & ~(hills | next_row | dales)
            while free_columns:
                curr_column = -free_columns & free_columns
                free_columns ^= curr_column
                count = backtrack(row + 1, 
                                  (hills | curr_column) << 1, 
                                  next_row | curr_column, 
                                  (dales | curr_column) >> 1, 
                                  count)
        return count
    columns = (1 << n) - 1
    return backtrack()

print(solution(int(input())))