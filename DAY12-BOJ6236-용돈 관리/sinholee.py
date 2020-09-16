import sys
n, m = map(int, input().split())
pocket_money = [int(sys.stdin.readline()) for _ in range(n)]

left = 0
right =10000000000

while left <= right:
    mid = (left + right) // 2
    cnt = 1
    flag = False
    temp_money = mid
    for i in range(n):
        if temp_money >= pocket_money[i]:
            temp_money -= pocket_money[i]
        else:
            temp_money = mid
            # 이부분이 관건
            if temp_money < pocket_money[i]:
                flag = True
                break
            cnt += 1
            temp_money -= pocket_money[i]
    if cnt > m or flag:
        left = mid + 1
    else:
        right = mid - 1
print(left)