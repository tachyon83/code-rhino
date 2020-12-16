def check(elements):
    stack = list()
    for e in elements:
        if e == '(':
            stack.append(e)
        elif e == ')' and stack:
            stack.pop()
        elif e == ')' and not stack:
            return False

    return False if stack else True

for _ in range(int(input())):
    print('YES' if check(input()) else 'NO')
