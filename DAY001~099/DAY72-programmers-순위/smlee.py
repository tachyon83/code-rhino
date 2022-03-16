def solution(n, results):
    w = {x:set() for x in range(1, n+1)}
    l = {y:set() for y in range(1, n+1)}
    answer = 0
    
    for winner, loser in results:
        w[winner].add(loser)
        l[loser].add(winner)
        
    for i in range(1, n+1):
        for winner in l[i]:
            w[winner].update(w[i])
        for loser in w[i]:
            l[loser].update(l[i])
 
    for i in range(1, n+1):
        if len(w[i]) + len(l[i]) == n-1:
            answer += 1
    return answer
