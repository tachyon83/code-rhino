def solution(id_list, report, k):
    answer = [0 for _ in range(len(id_list))]
    reports=dict()
    for rep in report:
        a,b=rep.split()
        if b not in reports:reports[b]=set()
        reports[b].add(a)

    reported=list(reports.keys())
    filtered=[]
    for e in reported:
        if len(reports[e])>=k:filtered.append(e)
    
    for i,e in enumerate(id_list):
        for p in filtered:
            if e in reports[p]:answer[i]+=1

    return answer
