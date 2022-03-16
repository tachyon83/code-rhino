text=input()
bomb=input()

ans=[]

for i in text:
    #하나씩 스택에 넣어준다
    ans.append(i)
    #ans와 bomb의 길이가 같으면
    if len(ans)>=len(bomb):
        #뒤에서 부터 검사 왜냐하면 앞에서부터 하면 112ab고 12ab일때 일치 하지 않기때문
        check = []
        checkcount=0
        same = True
        for j in range(-1,(-len(bomb))-1,-1):
            if ans[j] != bomb[j]:
                #하나라도 다르면 false
                same = False
                break
        
        if same == True:
            a=0
            #bomb의 길이만큼 pop
            while a<len(bomb):
                ans.pop()
                a+=1

#길이가 0이면 FRULA
if len(ans)==0:
    print("FRULA")
else:
    str=""
    for i in ans:
        str+=i
    print(str)
