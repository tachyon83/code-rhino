def solution(brown, red):
    total = brown + red
    for i in range(1, total+1):
        if total % i != 0:
            continue
        ans = total // i
        if (i-2)*(ans-2) == red:
            return sorted([i, ans], reverse = True)
