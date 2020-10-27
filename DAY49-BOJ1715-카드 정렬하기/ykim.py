import heapq

n = int(input())
heap = []

for _ in range(n):
    num = int(input())
    heapq.heappush(heap, num)

result = 0

while len(heap) != 1:
    num1 = heapq.heappop(heap)
    num2 = heapq.heappop(heap)
    _sum = num1 + num2
    result += _sum
    heapq.heappush(heap, _sum)

print(result)

'''
n = int(input())
arr = []
k = 0
sum = 0

for i in range(n):
    s = int(input())
    arr.append(s)

arr.sort()

for i in range(n):
    k = arr[i] * (n - i)
    sum += k

print(sum - arr[0])

'''
