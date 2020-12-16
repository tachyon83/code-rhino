def solution(w, h):
    answer = w*h
    small = gcd(w, h)
    W = w // small
    H = h // small

    answer -= small * H * W
    safe = 0
    for i in range(1, W):
        safe += i * H//W
    return answer + safe * 2 * small


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)
