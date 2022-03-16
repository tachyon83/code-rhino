def solution(relation):
    k = len(relation[0])
    mx, keyset = 1 << k, set()
    for i in range(1, mx):
        nxtflag = False
        for prvkey in keyset:
            if (i & prvkey) == prvkey:
                nxtflag = True
                break
        if nxtflag:
            continue
        hold, flag = set(), False
        for e in relation:
            tuple_temp = list()
            for j in range(k):
                if i & (1 << j):
                    tuple_temp.append(e[j])
            tuple_temp = tuple(tuple_temp)
            if tuple_temp not in hold:
                hold.add(tuple_temp)
            else:
                flag = True
                break
        if not flag:keyset.add(i)

    return len(keyset)
