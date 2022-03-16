import sys
#sys.stdin = open("input.txt", "r")
num_size, target = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
count = 0

for i in range(num_size):
    temp_target = target
    for j in range(i, num_size):
        temp_target -= nums[j]
        if temp_target == 0:
            count += 1
            break
        elif temp_target < 0:
            break
        else:
            continue
print(count)


