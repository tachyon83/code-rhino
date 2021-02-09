import sys
si = sys.stdin.readline

def solve(nums):
    m,hold,sign=-1,False,0
    for e in nums:
        if not hold:
            hold=e
            if e>0:sign=True
            elif e<0:sign=False
            else: sign=0
        else:
            if sign and e>0:
                hold+=e
            elif not sign and e<0:
                hold+=e
            elif not e:
            else:
                m=max(m,abs(hold))
                hold=e
                if e>0:sign=True
                elif e<0:sign=False
                else: sign=0
    m=max(m,abs(hold))
    return m
