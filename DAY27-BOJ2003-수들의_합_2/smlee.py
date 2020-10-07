'''
늦었지만 올려봅니다!
'''
N, M = map(int, input().split(' '))
A = list(map(int, input().split(' ')))

result = 0
x = 0
end = 0

for start in range(N) :
    while x < M and end < N :
        x += A[end]
        end += 1
    if x == M :
        result += 1
    x -= A[start]

print(result)
