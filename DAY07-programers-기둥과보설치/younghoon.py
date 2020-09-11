def solution(n, build_frame):
    def check(result):
        for x, y, type in result:
            if type == 0: #기둥
                if (y == 0 or (x-1, y, 1) in result or (x, y, 1) in result or (x, y-1, 0)in result) is False:
                    return False
            else: #보
                if((x, y-1, 0) in result or (x+1, y-1, 0) in result or ((x-1, y, 1) in result and (x+1, y, 1) in result)) is False:
                    return False
    result = set()
    for input in build_frame:
        x, y, type, action = input
        if action == 1: #insert
            result.add((x,y,type))
            if check(result) is False:
                result.remove((x,y,type))
        else: #delete
            if (x,y,type) in result:
                result.remove((x,y,type))
                if check(result) is False:
                    result.add((x,y,type))
    return sorted([list(s) for s in result], key = lambda x: (x[0], x[1], x[2]))
