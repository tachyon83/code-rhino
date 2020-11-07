def solution(w,h):
    if w == h : return (w * h - w)
    def gcd(a,b):
        if b==0 : return a
        return gcd(b, a%b)

    if w > h :
        l = w
        s = h
    else :
        l = h
        s = w
    
    g = gcd(l,s)
    return w*h-(w+h-g)
