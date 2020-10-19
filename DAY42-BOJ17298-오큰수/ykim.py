import sys

n=int(input())

input=list(map(int,sys.stdin.readline().split())) #입력받은 수열
stack=[]      #인덱스를 담아줄 스택
result=[-1 for _ in range(n)] #모두 -1로 초기화

stack.append(0) 
i=1
while stack and i<n: #수열의 수만큼 반복
    while stack and input[stack[-1]]<input[i]:# 스택의 탑에 해당하는 인덱스 값이 입력받은 수열보다 작으면
        result[stack[-1]]=input[i]#result[index]에 위치하는 값(result[stack[-1]])을 input[i]로 바꾸어준다.
        stack.pop()#스택에서 해당 index를 빼주고 다시 비교문실행

    stack.append(i) #스택에 인덱스를 넣는다
    i+=1#인덱스를 하나늘린다.

for i in range(n):
    print(result[i],end=" ")
