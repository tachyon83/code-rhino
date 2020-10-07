n = int(input())
b = input().split()
c = [False]*10 # 0~9
mx, mn = "", ""

def possible(i,j,k): # 가능한지 불가능한지 판단해주는 함수
    if k == '<':
        return i<j
    if k == '>':
        return i>j
    return True

def solve(cnt, s):

    global mx, mn
    if cnt == n+1:
        if not len(mn): # mn이 비워져 있으면 최솟값에 s 넣기
            mn = s
        else: # mn에 값이 있으면 최댓값에 넣기
            mx = s
        return
    for i in range(10):# 0부터 9까지 
        if not c[i]: # c[i]이 false이면(중복 방지)
            if cnt==0 or possible(s[-1], str(i), b[cnt-1]):
                c[i]=True
                solve(cnt+1, s+str(i)) 
                # 만약 0 > ? 일 경우 ?에 올 숫자가 없으므로 solve함수가 끝나고 c[0]이 false가 되고 c[1]부터 다시 시작한다.
                c[i]=False


solve(0, "")
print(mx)
print(mn)
