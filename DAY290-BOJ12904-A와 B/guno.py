import sys
input=sys.stdin.readline

s,t=input().rstrip(),input().rstrip()
ls,lt=len(s),len(t)
flag=False
_range=[0,lt-1,False]
for i in range(lt-ls):
    l,r,rev=_range
    if not rev:
        if t[r]=='B':
            rev=not rev
        _range=[l,r-1,rev]
    else:
        if t[l]=='B':
            rev=not rev
        _range=[l+1,r,rev]

l,r,rev=_range
if t[l:r+1]==(s if not rev else s[::-1]):
    print(1)
else:
    print(0)
