n, m, l = map(int, input().split())
arr = [0] + sorted([*map(int, input().split())]) +[l]
DEBUG = False
# 찾아야 할것 -> 내가 구하고 싶은 값을 기준으로
# focusing (여기선 mid)하는 값이 크거나 작다를 구분하여
# 목적에 부합하는 값(mid가 목적에 맞는지)을 찾아내는 로직이 필요 -> 이분탐색
# focusing 값을 기준으로 모든 길을 훑어보면서 몇개의 휴게소를 세울 수 있는지 파악해야 한다.
# 새로 생긴 휴게소 개수가 m보다 많으면 focusing 값을 키우고
# 새로 생긴 휴게소 개수가 m보다 적으면 focusing 값을 줄이면서
left = 0
right = l
if DEBUG:
    print(arr)
while left <= right:  # 왼쪽 오른쪽이 서로 엇나가야만 멈추로독 설계
    mid = (left + right) // 2
    cnt = 0
    if DEBUG:
        print("======================================")
        print("left: %s, mid: %s, right: %s" % (left, mid, right))
    for i in range(0, n+1):
        dist = arr[i+1] - arr[i]
        cnt += (dist // mid)
        if dist % mid == 0:
            cnt -= 1
        if DEBUG:
            print("dist: ", dist, "cnt: ", cnt, "div: ", dist//mid, "mod: ", dist % mid)
    
    if cnt <= m:
        right = mid - 1
    else:
        left = mid + 1
print(left)


