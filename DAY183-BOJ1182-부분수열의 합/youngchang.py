from itertools import combinations as comb


N, S = map(int, input().split())
nums = list(map(int, input().split()))

answer = 0
size = 1
while size <= N:
    for c in comb(range(N), size):
        if sum(nums[i] for i in c) == S:
            answer += 1
    size += 1

print(answer)