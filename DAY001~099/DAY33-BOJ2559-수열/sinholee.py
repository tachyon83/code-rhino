n, k = map(int, input().split())

arr = [*map(int, input().split())]
curr = sum((arr[i] for i in range(k)))
res = max(-100000001, curr)
for i in range(n-k):
    curr = curr + arr[i+k] - arr[i]
    res = max(curr, res)
print(res)

