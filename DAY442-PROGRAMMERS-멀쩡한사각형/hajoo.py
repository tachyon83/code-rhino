def uclid(a, b):
    if b == 0:
        return a
    
    return uclid(b, a % b)

def solution(w,h):
    gcd = uclid(w, h)

    return w * h - (w // gcd + h // gcd - 1) * gcd
