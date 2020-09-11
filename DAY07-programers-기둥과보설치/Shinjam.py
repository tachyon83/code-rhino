def is_ok(current):
    for x, y, a in current:
        if a == 0: # 기둥 조건
            check = [
                y == 0,
                (x - 1, y, 1) in current,
                (x, y, 1) in current, 
                (x, y - 1, 0) in current
            ]
        elif a == 1: # 보 조건
            check = [
                (x, y - 1, 0) in current,
                (x + 1, y - 1, 0) in current,
                (x - 1, y, 1) in current and (x + 1, y, 1) in current
            ]

        if not any(check):
            return False
    return True

def solution(n, build_frame):
    current = set()
    for x, y, a, b in build_frame:
        if b == 1:
            current.add((x, y, a))
            if not is_ok(current):
                current.remove((x, y, a))
        elif b == 0:
            current.remove((x, y, a))
            if not is_ok(current):
                current.add((x, y, a))
    ret = [list(r) for r in current]
    return sorted(ret)
