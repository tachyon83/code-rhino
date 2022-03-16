import sys
si=sys.stdin.readline

s, N, K, R1, R2, C1, C2=[int(e) for e in si().split()]

def dnc(sz,r,c):
    global N,K
    if sz==1:return '0'
    sz//=N
    left,right=sz*(N-K)//2,sz*(N+K)//2
    if left<=r<right and left<=c<right:return '1'
    return dnc(sz,r%sz,c%sz)

for r in range(R1,R2+1):
    st=''
    for c in range(C1,C2+1):st+=dnc(N**s,r,c)
    print(st)
