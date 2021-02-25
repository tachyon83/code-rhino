def solution(routes):
    cams = []
    for route in routes:
        if route[0] > route[1]:route = route[::-1]
        if not cams:
            cams.append(route)
            continue
        flag = False
        # cams.sort()
        for i, cam in enumerate(cams):
            a, b, c, d = cam[0], cam[1], route[0], route[1]
            if c < a:
                if d < a:continue
                else:
                    flag = True
                    if d > b:cams[i] = [a, b]
                    else:cams[i] = [a, d]
                    break
            else:
                if c > b:continue
                else:
                    flag = True
                    if d <= b:cams[i] = [c, d]
                    else:cams[i] = [c, b]
                    break

        if not flag:cams.append(route)
    return len(cams)
