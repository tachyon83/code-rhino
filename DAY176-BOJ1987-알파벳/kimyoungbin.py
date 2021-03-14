import sys


def bfs():
    max_len = 0
    queue = set()
    queue.add((0, 0, board[0][0]))
    while queue:
        r, c, sentence = queue.pop()
        max_len = max(max_len, len(sentence))
        if max_len == 26:
            break
        for dr, dc in dirs:
            new_r = r + dr
            new_c = c + dc
            if 0 <= new_r < R and 0 <= new_c < C:
                if board[new_r][new_c] not in sentence:
                    queue.add((new_r, new_c, sentence + board[new_r][new_c]))
    return max_len


dirs = [(0, -1), (0, 1), (-1, 0), (1, 0)]
R, C = map(int, sys.stdin.readline().split())
board = [list(map(str, sys.stdin.readline().strip())) for _ in range(R)]
print(bfs())
