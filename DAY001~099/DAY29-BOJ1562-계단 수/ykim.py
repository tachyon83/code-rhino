'''
개념이해에 도움이 된 블로그
https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=221130521559&proxyReferer=https:%2F%2Fwww.google.com%2F
'''


n = int(input())
 
re = 0
dp = [[0 for _ in range(1024)] for _ in range(10)]
 
for i in range(1, 10):
    dp[i][1<<i] = 1
 
for i in range(1, n):
    dp_next = [[0 for _ in range(1024)] for _ in range(10)]
    for e in range(10):
        for bm in range(1024):
            if e < 9:
                dp_next[e][bm | (1<<e)] = (dp_next[e][bm | (1<<e)] + dp[e+1][bm]) % 1000000000
            if e > 0:
                dp_next[e][bm | (1<<e)] = (dp_next[e][bm | (1<<e)] + dp[e-1][bm]) % 1000000000
    dp = dp_next
 
print(sum([dp[i][1023] for i in range(10)]) % 1000000000)


