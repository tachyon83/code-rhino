'''
https://www.acmicpc.net/board/view/21884 에서 힌트를 얻었습니다
아무것도 안하는 것도 하나의 방법이다 라는 훼이크 때매 여러번 틀렸네요..
'''
def func(a) :
    dp = [0, 1, 3]
    for i in range(3, a + 1):
        dp.append(dp[i - 1] + dp[i - 2] * 2)
    return dp[a]

while True :
    try :
        a = int(input())
        print(func(a))
    except :
        break
