text = input()
b_text = input()
stack = []

for i in text : 
  stack.append(i)
  if i == b_text[-1] and ''.join(stack[-len(b_text):]) == b_text :
    del stack[-len(b_text):]

if not stack :
  print('FRULA')
else :
  print(''.join(stack))
