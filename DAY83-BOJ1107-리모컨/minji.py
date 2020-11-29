import sys

def sol():
   ans = abs(n-100)

   for i in range(1000001):
       tf = True
       for j in str(i):
           if j not in ch:
               tf = False
               break
       if tf:
          ans = min(ans, abs(n-i)+len(str(i)))
   return ans

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    if m != 0:
        _remove = list(map(str, sys.stdin.readline().split()))
    else:
        _remove = []
    ch = [str(i) for i in range(10) if str(i) not in _remove]

    print(sol())
