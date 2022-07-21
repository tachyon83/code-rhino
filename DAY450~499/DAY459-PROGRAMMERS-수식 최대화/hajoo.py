import re

ans = 0

def traverse(visited, expression):
    global ans

    if len(visited) == 3:
        nums = re.split('[*+-]', expression)
        ops = re.split("[0-9]+", expression)
        for v in visited:
            while v in ops:
                idx = ops.index(v)
                nums[idx - 1] = str(eval(nums[idx - 1] + ops[idx] + nums[idx]))
                del nums[idx]
                del ops[idx]
        ans = max(ans, abs(int(nums[0])))

    for op in ['*', '+', '-']:
        if op not in visited:
            visited.append(op)
            traverse(visited, expression)
            visited.pop()

def solution(expression):
    traverse([], expression)

    return ans