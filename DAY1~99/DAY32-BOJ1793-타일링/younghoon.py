import sys
#sys.stdin = open("input.txt", "r")

def solve(i):
    fib = []
    fib.append(1)
    fib.append(1)
    fib.append(3)
    for x in range(3, i+1):
      fib.append(fib[x-2]*2 + fib[x-1])
    print(fib[i])


while True:
    try:
        solve(int(sys.stdin.readline().strip()))
    except:
        break


