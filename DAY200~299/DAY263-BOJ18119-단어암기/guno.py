import sys
input=sys.stdin.readline

n,m=map(int,input().split())
know=(1<<26)-1
words=[input().rstrip() for _ in range(n)]
for i in range(n):
    temp=0
    for c in words[i]:
        temp|=1<<(ord(c)-ord('a'))
    words[i]=temp
for _ in range(m):
    know^=1<<(ord(input().split()[1])-97)
    cnt=0
    for word in words:
        if know|word==know:
            cnt+=1
    print(cnt)
    
#pypy 사용
