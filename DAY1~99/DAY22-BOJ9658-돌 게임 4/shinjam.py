N = int(input())
DP = {0:1, 1:0, 2:1, 3:0, 4:1, 5:1, 6:1}
print('SK' if DP[N % 7] else 'CY')
