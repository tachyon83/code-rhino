T = int(input())


def get_coin_cnt(num):
    cnt = 0
    # 1 10의 0승 2승 4승 ....2n승
    for exp in range(16, 0, -2):
        min_exp, max_exp = exp-2, exp
        target_num = num // (10 ** min_exp)
        num = num % (10 ** min_exp)
        if target_num:
            dp =[99 for i in range(target_num+1)]
            dp[0] =0
            coins = [1, 10, 25]
            for j in range(1, target_num+1):
                for coin in coins:
                    if coin<=j:
                        dp[j] = min(dp[j], dp[j-coin]+1)
            cnt += dp[target_num]
    return cnt

for t in range(T):
    num = int(input())
    print(get_coin_cnt(num))


