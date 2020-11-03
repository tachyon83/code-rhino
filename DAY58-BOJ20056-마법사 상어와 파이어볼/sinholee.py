def solution(n, m, k, dic):
    def move(y, x, d, s):
        dy = [-1, -1, 0, 1, 1, 1, 0, -1]
        dx = [0, 1, 1, 1, 0, -1, -1, -1]
        rnd = 0
        ny = (y + s*dy[d])%n
        nx = (x + s*dx[d])%n
        return ny, nx

    def is_all_even_or_odd(directions):
        pivot = directions[0]
        for diction in directions:
            if pivot % 2 != diction % 2:
                return False
        return True

    # 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    # 파이어볼은 4개의 파이어볼로 나누어진다.
    # 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
    # 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
    # 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
    # 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    # 질량이 0 인 파이어볼은 소멸한다
    def merge(values):
        total_m, total_s = 0, 0
        directions = []
        cnt_s = 0
        for value in values:
            m, s, d = value
            directions.append(d)
            total_m += m
            total_s += s
            cnt_s += 1
        if total_m >=5:
            if is_all_even_or_odd(directions):
                return [(total_m // 5, total_s // cnt_s, 0), (total_m // 5, total_s // cnt_s, 2), (total_m // 5, total_s // cnt_s,4), (total_m // 5, total_s // cnt_s,6)]
            else:
                return [(total_m // 5, total_s // cnt_s,1), (total_m // 5, total_s // cnt_s,3), (total_m // 5, total_s // cnt_s,5), (total_m // 5, total_s // cnt_s,7)]
        else:
            return []

    # k 번 반복한다
    while k:
        k -= 1
        new_dic = {}
        # 새로운 공간에 이동한 파이어볼을 적재한다.
        for key, values in dic.items():
            y, x = key
            for value in values:
                m, s, d = value
                ny, nx = move(y, x, d, s)
                if new_dic.get((ny, nx)) is None:
                    new_dic[(ny, nx)] = [(m, s, d)]
                else:
                    new_dic[(ny, nx)].append((m, s, d))
        # 적재한 파이어볼 중 두개 이상인 애들을 다음과 같은 일을 한다
        dic = {}
        for key, values in new_dic.items():
            if len(values) > 1:
                new_values = merge(values)
                if len(new_values):
                    dic[(key[0], key[1])] = new_values
            else:
                dic[(key[0], key[1])] = values
                

    # 남은 파이어볼의 총 질량을 구한다.
    res = 0
    for key, values in dic.items():
        for value in values:
            m,s,d = value 
            res += m
    return res
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    dic = {}
    for _ in range(m):
        y, x, m, d, s = map(int, input().split())
        y, x = y-1, x-1
        dic[(y, x)] = [(m, d, s)]
    print(solution(n, m, k, dic))

