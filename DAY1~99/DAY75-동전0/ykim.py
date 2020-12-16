#값 입력
N, K = map(int, input().split())
Money = [int(input()) for _ in range(N)]

#코인 총 개수 입력 변수
num = 0

#알고리즘
#큰 값이 있는 뒤의 인덱스부터 계산
for i in range(1,N+1): #1
    coin = Money[-i] #2
    if K >= coin: #3
        mok = K//coin #4
        K -= coin*mok #5
        num += mok #6
        
print(num)
