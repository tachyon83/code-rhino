def solution(n):
    cnt,a=0,bin(n)[2:]
    for e in a:
        if e=='1':cnt+=1
    return cnt
