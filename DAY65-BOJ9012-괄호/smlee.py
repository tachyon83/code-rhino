t = int(input())

def solution(brackets) :
  stack = []

  for i in brackets :
    if i == ')' and not stack:
      return print('NO')
    elif i == '(' :
      stack.append(i)
    elif i == ')' and stack:
      stack.pop()
  
  if len(stack) == 0 :
    return print('YES')
  else :
    return print('NO')

for _ in range(t) :
  solution(input())
