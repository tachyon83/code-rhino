# 2
# 5 6
# 0 0 1 0
# 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)개수
import sys

N = int(input())
numbers = list(map(int, sys.stdin.readline().split()))
add, sub, mul, div = map(int, sys.stdin.readline().split())

max_val = -sys.maxsize
min_val = sys.maxsize


def dfs(result, count):
    global add, sub, mul, div, max_val, min_val
    # base case
    # print(min_val)
    # print(max_val)
    # print("dfs running")
    if count == N-1:
        # print("haha")
        min_val = min(result, min_val)
        max_val = max(result, max_val)
        return
    # print("what?")
    if add >= 1:
        add -= 1
        dfs(result + numbers[count + 1], count + 1)
        add += 1
    if sub >= 1:
        sub -= 1
        dfs(result - numbers[count + 1], count + 1)
        sub += 1
    if mul >= 1:
        mul -= 1
        dfs(result * numbers[count + 1], count + 1)
        mul += 1
    if div >= 1:
        div -= 1
        dfs(int(result / numbers[count + 1]), count + 1)
        div += 1
    # print("hell yah")    
        
dfs(numbers[0], 0)
print(max_val)
print(min_val)
