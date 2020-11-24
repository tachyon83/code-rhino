def solution(answers):
    A = [1, 2, 3, 4, 5]
    B = [2, 1, 2, 3, 2, 4, 2, 5]
    C = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    cnt = [0, 0, 0]

    
    for q in range(len(answers)):
        if A[q % len(A)] == answers[q]:
            cnt[0] += 1
        if B[q % len(B)] == answers[q]:
            cnt[1] += 1
        if C[q % len(C)] == answers[q]:
            cnt[2] += 1
            
    return [idx + 1 for idx, val in enumerate(cnt) if val == max(cnt)]
