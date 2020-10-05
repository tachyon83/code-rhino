k = int(input())
arr = list(map(str, input().split()))


def is_correct(a, b, symbol):
    if symbol == "<":
        return a < b
    return a > b


def get_min_nums(k):
    s = ""
    for i in range(k+1):
        s += str(i)
    return s


def get_max_nums(k):
    s = ""
    for i in range(9, 9-k-1, -1):
        s += str(i)
    return s


def perm(depth, visited, target, length, res, arr, is_max, callback):
    if depth == length:
        return res
    min_value = "99999999999"
    max_value = "0"
    for i in range(length):
        if visited[i]:
            continue
        if depth == 0 or callback(res[-1], target[i], arr[depth-1]):
            visited[i] = 1
            temp = perm(depth+1, visited, target, length, res+target[i], arr, is_max, callback)
            if is_max:
                max_value = max(temp, max_value)
            else:
                min_value = min(temp, min_value)
            visited[i] = 0
    return max_value if is_max else min_value


print(perm(0, [0] * (k+1), get_max_nums(k), k+1, "", arr, True, is_correct))
print(perm(0, [0] * (k+1), get_min_nums(k), k+1, "", arr, False, is_correct))

