n = int(input())

mat = [list(map(int, input())) for _ in range(n)]


def is_one_or_zero(sy, sx, ey, ex):
    pivot = mat[sy][sx]
    for i in range(sy, ey):
        for j in range(sx, ex):
            if pivot != mat[i][j]:
                return False
    return str(pivot)


def solution(sy, sx, ey, ex):
    s = ""
    res = is_one_or_zero(sy, sx, ey, ex)
    if res:
        return res

    mid1 = (sy+ey) // 2
    mid2 = (sx+ex) // 2
    s += solution(sy, sx, mid1, mid2) # 왼쪽 위
    s += solution(sy, mid2, mid1, ex) # 오른쪽 위
    s += solution(mid1, sx, ey, mid2) # 왼쪽 아래
    s += solution(mid1, mid2, ey, ex)
    return '(' + s + ')'
