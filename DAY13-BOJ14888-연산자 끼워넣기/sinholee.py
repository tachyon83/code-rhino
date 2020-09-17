n = int(input())
numbers = list(map(int, input().split()))
operators = list(map(int, input().split()))


def operation(a, b, op):
    if op == 0:
        return a + b
    elif op == 1:
        return a-b
    elif op == 2:
        return a * b
    else:
        if a < 0 and b > 0:
            a *= -1
            res = a // b
            res *= -1
        else:
            res = a // b
        return res

def cal(idx, depth, res):
    if depth == n-1:
        cal_set.add(res)
        return
    for i in range(4):
        if operators[i] != 0:
            operators[i] -= 1
            cal(idx+1, depth+1, operation(res, numbers[idx+2], i))
            operators[i] += 1




cal_set = set([])
for i in range(4):
    if operators[i] != 0:
        operators[i] -= 1
        cal(0, 1, operation(numbers[0], numbers[1], i))
        operators[i] += 1
print(max(cal_set))
print(min(cal_set))
