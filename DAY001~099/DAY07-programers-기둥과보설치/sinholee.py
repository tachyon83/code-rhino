
def solution(n, build_frame):
    answer = []
    mat = [[[0, 0] for _ in range(n+1)]for _ in range(n+1)]

    def is_buildable_bo(y, x, a):  # a == 1
        if 0 <= y - 1 < n+1 and mat[y - 1][x][a ^ 1]:  # 보의 왼쪽 끝부분 아래 기둥
            return True
        elif 0 <= y - 1 < n+1 and 0 <= x + 1 < n+1 and mat[y - 1][x + 1][a ^ 1]:  # 보 오른쪽 끝부분 아래 기둥
            return True
        elif (0 <= x - 1 < n+1 and mat[y][x - 1][a]) and (0 <= x + 1 < n+1 and mat[y][x + 1][a]):  # 왼쪽과 오른쪽에 보가 모두 있을경우
            return True
        return False

    def is_buildable_ki(y, x, a):
        if y == 0:  # 바닥 위에 세울 경우
            return True
        elif 0 <= y - 1 < n+1 and mat[y - 1][x][a]:  # 기둥위에 세울 경우
            return True
        elif mat[y][x][a ^ 1]:  # 내 밑에 보가 있을경우
            return True
        elif 0 <= x - 1 < n+1 and mat[y][x - 1][a ^ 1]:  # 왼쪽 밑에 보가 있을경우
            return True
        return False

    for arr in build_frame:
        x, y, a, b = arr
        # 생성
        if b:
            if a: # 보를 생성할때, a == 1
                if is_buildable_bo(y, x, a):
                    mat[y][x][a] = 1
            else: # 기둥을 생성할때, a == 0
                if is_buildable_ki(y, x, a):
                    mat[y][x][a] = 1
        else:
            mat[y][x][a] = 0  # 일단 삭제 해보고, 주위 객체들이 살아남을 수 있는지 판단하여 상태 관리
            if a: # 보를 삭제할때  a == 1
                if 0 <= x-1 < n +1 and mat[y][x-1][a]:  # 지우려는 보 왼쪽에 보가 있을때
                    if not is_buildable_bo(y, x-1, a):  # 보가 살아남을 수 없다면,
                        mat[y][x][a] = 1  # 지우지 않는다.
                if 0 <= x + 1 < n +1 and mat[y][x + 1][a]:  # 지우려는 보 오른쪽에 보가 있을때
                    if not is_buildable_bo(y, x + 1, a):  # 보가 살아남을 수 없다면,
                        mat[y][x][a] = 1  # 지우지 않는다.
                if 0 <= y < n +1 and mat[y][x][a^1]:  #지우려는 보 위에 기둥이 있을때
                    if not is_buildable_ki(y, x, a^1):  # 기둥이 살아남을 수 없다면
                        mat[y][x][a] = 1  # 지우지 않는다.
                if 0 <= y < n +1 and 0 <= x+1 < n+1 and mat[y][x+1][a^1]:  # 지우려는 보 위, 오른쪽 기둥이 있을때
                    if not is_buildable_ki(y, x+1, a^1):  # 기둥이 살아남을 수 없다면
                        mat[y][x][a] = 1  # 지우지 않는다.
            else: # 기둥을 삭제할때 a == 0
                if 0 <= y+1 < n+1 and mat[y+1][x][a]:  # 지우려는 기둥 위에 기둥이 있을때,
                    if not is_buildable_ki(y+1, x, a): # 그 기둥이 살아있을 수 없다면
                        mat[y][x][a] = 1  # 지울 수 없다.
                        continue
                if 0 <= y+1 < n +1 and mat[y+1][x][a^1]:  # 지우려는 기둥위에 보가 있을때,
                    if not is_buildable_bo(y+1, x, a^1):  # 보가 살아남을 수 없다면
                        mat[y][x][a] = 1  # 지울 수 없다.
                        continue
                if 0 <= y+1 < n +1 and 0 <= x-1 < n +1 and mat[y+1][x-1][a^1]:  # 지우려는 기둥 위, 왼쪽에 보가 있을때,
                    if not is_buildable_bo(y+1, x-1, a^1):  # 보가 살아남을 수 없다면
                        mat[y][x][a] = 1
    for j in range(n+1):
        for i in range(n+1):
            if mat[i][j][0]:
                answer.append([j, i, 0])
            if mat[i][j][1]:
                answer.append([j, i, 1])
    return answer
