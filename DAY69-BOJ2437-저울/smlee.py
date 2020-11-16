n = int(input())
w = list(map(int, input().split()))
w.sort()
num = 1
for i in range(n):
    if num < w[i]:
        break
    num += w[i]
print(num)
