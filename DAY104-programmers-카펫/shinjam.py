from math import sqrt
def solution(brown, yellow):
    ret = []
    for i in range(int(sqrt(yellow)) + 1, 0, -1):
        if not yellow % i:
            ret.append([i, yellow // i])
    for x in ret:
        if x[0] * 2 + x[1] * 2 + 4 == brown:
            ret = [x[0] + 2, x[1] + 2]
    ret.sort(reverse=True)
    return ret
