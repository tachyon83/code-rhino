import sys
input=sys.stdin.readline

T=int(input())
for _ in range(T):
    N=int(input())
    stocks=list(map(int,input().split()))
    answer=0
    stack=[]
    for stock in stocks:
        if stack==[] or stack[-1][0]>stock:
            stack.append([stock,1])
        else:
            num=1
            while stack!=[] and stack[-1][0]<=stock:
                answer+=(stock-stack[-1][0])*stack[-1][1]
                num+=stack[-1][1]
                stack.pop()
            stack.append([stock,num])
    print(answer)