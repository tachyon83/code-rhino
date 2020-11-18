def solution(n, results):
    win = {x:set() for x in range(1, n+1)}
    lose = {x:set() for x in range(1, n+1)}
    for winner, loser in results:
        win[winner].add(loser)
        lose[loser].add(winner)
    for i in range(1, n+1):
        for winner in lose[i]:
            win[winner].update(win[i])
        for loser in win[i]:
            lose[loser].update(lose[i])
    answer = 0
    for i in range(1, n+1):
        if len(win[i]) + len(lose[i]) == n-1:
            answer += 1
    return answer
