import sys
#sys.stdin = open("input.txt", "r")

size = int(sys.stdin.readline())
inequalities = list(sys.stdin.readline().split())
visited = [False] * 10
min_val, max_val = sys.maxsize, -sys.maxsize

def compare(a,b,op):
    if op == '<':
        return a<b
    else:
        return a>b
        
def solve(depth, prev):
    global max_val, min_val
    if depth == size+1:
        max_val = max(max_val, int(prev))
        min_val = min(min_val, int(prev))
    else:
        for i in range(10):
            if not visited[i]:
                if depth == 0 or compare(prev[-1], str(i), inequalities[depth-1]):
                    visited[i] = True
                    solve(depth+1, prev+str(i))
                    visited[i] = False

solve(0, "")
max_val, min_val = str(max_val), str(min_val)
if len(max_val) != len(min_val):
    min_val = '0' + min_val

print(max_val)
print(min_val)
