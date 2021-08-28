N, C = map(int, input().split())
M = int(input())
info = []
for i in range(M):
    info.append(list(map(int, input().split())))
info.sort(key=lambda x: x[1])

arr = [0 for _ in range(2001)]
ret = 0

for i in range(M):
    minBox = 1000000
    for j in range(info[i][0],info[i][1]):
        minBox = min(minBox, C-arr[j])
    maxBox=min(minBox,info[i][2])
    ret+=maxBox
    for j in range(info[i][0],info[i][1]):
        arr[j]+=maxBox

print(ret)
