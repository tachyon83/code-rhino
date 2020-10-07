'''
너무 어려워서 복붙했습니다ㅜ(https://hddcp.tistory.com/18)
알고리즘 개념 정도만 이해했네요(dp개념, 비트마스크)
갈 길이 먼 것 같은데 좀 더 실력이 늘면 다시 풀어봐야겠습니다..
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
