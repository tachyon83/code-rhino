def solution(n, results):
    wins, loses = {}, {}
    for i in range(1, n+1):
        wins[i], loses[i] = set(), set()
        
    for a, b in results:
        wins[a].add(b)
        loses[b].add(a)
    
    for i in range(1, n+1):
        for lose in wins[i]:
            loses[lose].update(loses[i])
        for win in loses[i]:
            wins[win].update(wins[i])
    ans = 0
    for i in range(1, n+1):
        if len(wins[i]) + len(loses[i]) == n-1:
            ans += 1
    return ans
