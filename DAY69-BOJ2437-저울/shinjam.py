import sys 
N = int(sys.stdin.readline())
weights = sorted(map(int, sys.stdin.readline().split()))
acc = 1
for i in range(N):
    if weights[i] > acc:
        break
    acc += weights[i]
print(acc)
