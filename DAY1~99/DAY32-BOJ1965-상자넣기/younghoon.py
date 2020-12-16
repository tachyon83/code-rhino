n = int(input()) 
box = list(map(int, input().split())) 
size = [0] * 1001 
for b in box: 
    size[b] = max(size[:b]) + 1
print(max(size))
