import sys

N, C = map(int, sys.stdin.readline().split())
array = list(int(sys.stdin.readline()) for _ in range(N))
array.sort()

start, end = array[1] - array[0], array[-1] - array[0]
result = 0

while start <= end:
    mid = (start + end)//2
    value = array[0]
    count = 1
    for i in range(1, N):
        if array[i] >= value + mid:
            value = array[i]
            count += 1
    if count >= C:
        start = mid + 1
        result = mid
    else:
        end = mid - 1
print(result)

