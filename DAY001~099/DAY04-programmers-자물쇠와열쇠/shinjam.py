def check(key, lock, start_x, start_y):
    big_lock = [[0] * BL_N for _ in range(BL_N)] # 패딩 lock
        
    # 검사 열쇠 대입
    for idx in range(K_N ** 2):
        x, y = divmod(idx, K_N)
        big_lock[x + start_x][y + start_y] = key[x][y]

    # 자물쇠 확인
    for idx in range(L_N ** 2):
        x, y = divmod(idx, L_N)
        if big_lock[x + K_N - 1][y + K_N - 1] + lock[x][y] != 1:
            return False
        
    return True
        


def solution(key, lock):
    global K_N, L_N, BL_N
    K_N, L_N = len(key), len(lock)
    BL_N = L_N * 3 - 2
    
    # 회전
    for _ in range(4):
        key = list(zip(*key[::-1]))

        for idx in range(BL_N ** 2):
            i, j = divmod(idx, BL_N)
            if i > BL_N - K_N or j > BL_N - K_N:
                continue

            # 각각의 키 확인
            if check(key, lock, i, j):
                return True

    return False
