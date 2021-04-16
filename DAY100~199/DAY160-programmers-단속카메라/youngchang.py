from collections import defaultdict
def solution(routes):
    answer = 0
    routes.sort(key = lambda x : x[1])
    while routes:
        cand_dic = defaultdict(int)
        for cand in [i[1] for i in routes]:
            for st,ed in routes:
                if cand<st:
                    continue
                elif st<=cand<=ed:
                    cand_dic[cand]+=1
                else:
                    break
        spot = max(cand_dic, key = lambda x : x.__getitem__)
        remove_lst = []
        for i,j in enumerate(routes):
            if spot<j[0]:
                continue
            elif j[0]<=spot<=j[1]:
                remove_lst.append(i)
            else:
                break
        for i in remove_lst[::-1]:
            del routes[i]
        answer+=1
    return answer