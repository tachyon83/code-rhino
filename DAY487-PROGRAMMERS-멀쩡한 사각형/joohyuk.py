def gcd(a,b):return gcd(b,a%b) if b else a
def solution(w,h):return w*h-(w+h-gcd(w,h))
