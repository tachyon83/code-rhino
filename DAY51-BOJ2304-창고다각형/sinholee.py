T = int(input())
nums = []
for t in range(T):
    num = list(map(int, input().split()))
    nums+=[num]

max_idx = 0
max_height = 0
for n in range(len(nums)):
    if max_idx <= nums[n][0]:
        max_idx = nums[n][0]
    if max_height <= nums[n][1]:
        max_height = nums[n][1]
#  창고바닥 리스트 만들기
bottom = [False] +[0] * max_idx

# 리스트 안에 높이 적용하기
for n in range(len(nums)):
    bottom[nums[n][0]] = nums[n][1]

# 최고층 구하기
max_idx_list = []
for h in range(1, len(bottom)): # h는 인덱스, bottom[h]는 높이
    if max_height == bottom[h]:
        max_idx_list += [h]

result = [0] * (max_idx + 1)

i = 1
max_height = 0
while i != max_idx_list[0]:
    if max_height <= bottom[i]:
        max_height = bottom[i]
        result[i] = max_height
    else:
        result[i] = max_height
    i += 1

ii = max_idx_list[0]
while ii != (max_idx_list[-1]+1):
    result[ii] = bottom[max_idx_list[0]]
    ii += 1

iii = max_idx
max_height = 0
while iii != max_idx_list[-1]:
        if max_height <= bottom[iii]:
            max_height = bottom[iii]
            result[iii] = max_height
        else:
            result[iii] = max_height
        iii -= 1

print(sum(result))
