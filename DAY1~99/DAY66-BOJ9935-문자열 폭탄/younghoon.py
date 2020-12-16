import sys
#sys.stdin = open('input.txt', 'r')

s, bomb = input(), list(input())
stack = []
for char in s:
  stack.append(char)
  if char == bomb[len(bomb)-1] and stack[-len(bomb):] == bomb:
    del stack[-len(bomb):]
print(''.join(stack) if stack else 'FRULA')
