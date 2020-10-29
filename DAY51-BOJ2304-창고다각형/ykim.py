import sys

col = [0] * 1001
N = int(input())
col_range = [1001, 0]
max_c = 0
max_col = 0
max_index = 0
for _ in range(N):
    a, b = map(int, input().split())
    if a < col_range[0]:
        col_range[0] = a
    if a > col_range[1]:
        col_range[1] = a
    if b > max_c:
        max_c = b
        max_index = a
    col[a] = b
    
result = 0
if max_index == col_range[1]:
    for e in col[col_range[0]:col_range[1]+1]:
        if max_col < e:
            max_col = e
        result += max_col
elif max_index == col_range[0]:
    for e in col[col_range[1]:col_range[0]-1:-1]:
        if max_col < e:
            max_col = e
        result += max_col
else:
    for e in col[col_range[0]:max_index+1]:
        if max_col < e:
            max_col = e
        result += max_col
    max_col = 0
    for e in col[col_range[1]:max_index:-1]:
        if max_col < e:
            max_col = e
        result += max_col
print(result)
