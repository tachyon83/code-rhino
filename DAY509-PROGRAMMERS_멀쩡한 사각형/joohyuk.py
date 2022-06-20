def gcd(a,b):
    if b:return gcd(b,a%b)
    return a

def solution(w,h):return w*h-(w+h-gcd(w,h))
