import sys
si = sys.stdin.readline

DEBUF = False

def floyd_warshall(n):
    mat = [list(map(int, si().split())) for _ in range(n)]
    mat_for_calc = [[1] * n for _ in range(n)]
    for k in range(n):
        for u in range(n):
            for v in range(u+1, n):
                if u==k or v==k:
                    continue
                # 불가능한 경우 -> 이미 간선들이 최소값이라고 주어져 있는데, 
                # 막상 두 간선의 합이 최소값보다 작다면, 모든 최소 간선을 구한게 아니므로 불가능한 경우라고 할 수 있다.
                if mat[u][v] > mat[u][k] + mat[k][v]:
                    return -1
                if DEBUF:
                    print("u: %s k: %s v: %s mat[u][v]: %s mat[u][k]: %s mat[k][v]: %s " % (u, k, v, mat[u][v], mat[u][k], mat[k][v]))
                if mat[u][v] == mat[u][k] + mat[k][v]:
                    mat_for_calc[u][v] = 0
                    if DEBUF:
                        print("위 내용은 간선을 지울 경우")
                        print("")
    return sum(mat[i][j] if mat_for_calc[i][j] and i<j else 0 for j in range(n) for i in range(n)) 
    
    '''
    res = 0
    for i in range(n):
        for j in range(i+1, n):
            if mat_for_calc[i][j]:
                res += mat[i][j]
    # 위 로직과 아래 로직은 똑같은 로직으로 컴프리헨션을 이용한 계산인데... 왜 밑에꺼는 계산이 제대로 안되는거죠? 
    # j를 구하는 루프 구간에 i를 인식 못해서 그런건가... 그렇다면 어째서 인식을 못하는건지 이해가 안대요
    return sum(mat[i][j] if mat_for_calc[i][j] else 0 for j in range(i+1, n) for i in range(n)) 
    '''

print(floyd_warshall(int(si())))
