from math import gcd

def solution(w,h):
    GCD = gcd(w, h)
    x, y = w // GCD, h // GCD
    
    return w*h-GCD*(x+y-1)
