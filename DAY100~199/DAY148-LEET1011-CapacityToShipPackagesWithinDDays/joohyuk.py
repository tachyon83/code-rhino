import sys
si = sys.stdin.readline

def solve(weights,d):
    t=sum(weights)
    s,e=0,t

    while s<e:
        m=(s+e)//2
        hold,c=0,0

        for e in weights:
            if hold<m:
                hold+=e
            else:
                hold=e
                c+=1
        if c<d:
            e=m
        else:
            s=m
    print(s)
    
