i = int(input())
fib = []
fib.append(0)
fib.append(1)
fib.append(3)
for x in range(3, i+1):
  fib.append(fib[x-2]*2 + fib[x-1])
print(fib[i]% 10007)





