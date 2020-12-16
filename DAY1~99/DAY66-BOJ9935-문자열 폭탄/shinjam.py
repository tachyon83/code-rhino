case, bomb = input(), list(input())
bl = len(bomb)
stack = []
for c in case:
    stack.append(c)
    if c == bomb[-1] and stack[-bl:] == bomb:
        del stack[-bl:]
        
print(''.join(stack) if stack else 'FRULA')
