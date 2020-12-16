n = int(input())
s = list(map(int, input().split()))
s.sort()
num = 1
for i in range(n):
    if num < s[i]:
        break
    num += s[i]
print(num)
