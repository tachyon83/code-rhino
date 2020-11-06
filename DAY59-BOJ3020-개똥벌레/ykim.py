import sys
def Binary_Search_Upper(data_list, x):                  #주어진 list에서 x보다 큰 데이터의 개수를 반환; log n 안에 찾음
    left = 0
    right = len(data_list) - 1
    while left <= right:
        mid = (left + right) // 2
        if data_list[mid] <= x:
            left = mid + 1
        else:
            right = mid - 1
    return len(data_list) - (right + 1)                  #index, 개수 차이 때문에 1 더해줌

input_list = input().split()
N = int(input_list[0])
H = int(input_list[1])
data_down = []
data_up = []
for i in range(N):
    input_list_2 = sys.stdin.readline().split()
    input_num = int(input_list_2[0])
    if i % 2 == 0:              #아래부터 높이 재기
        data_down.append(input_num)
    else:                       #위부터 높이 재기
        data_up.append(input_num)
data_down.sort()
data_up.sort()
ans = N                         #장애물의 최솟값
cnt = 0                         #구간 몇 개 있는지
for h in range(1, H + 1):
    down_num = Binary_Search_Upper(data_down, h - 1)
    up_num = Binary_Search_Upper(data_up, H - h)
    cur_num = down_num + up_num     #현재 mid 값을 기준으로 잘랐을 때의 장애물의 수
    if cur_num < ans:               #새로운 최솟값이 나오면 정답 업데이트; 개수는 1부터 다시 셈
        ans = cur_num
        cnt = 1
    elif cur_num == ans:            #현재 최솟값과 같은 값이 한 번 더 나오면 개수 1 증가
        cnt += 1
print(ans, cnt)
