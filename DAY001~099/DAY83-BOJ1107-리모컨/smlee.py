rmt_num = {str(i) for i in range(10)}

N = int(input())
M = int(input())

if M != 0:
  rmt_num -= set(map(str, input().split()))

result = abs(N - 100)

for i in range(1000001):
    tf = True
    for num in str(i):
        if (num not in rmt_num):
            tf = False
            break
    if tf is True:
        result = min(result, abs(N - i) + len(str(i)))

print(result)
