n, c = map(int,input().split())
m = int(input())
town = [c] * (n-1)
result = 0

box_list = [list(map(int, input().split())) for _ in range(m)]
box_list.sort(key=lambda box_list: (box_list[1], box_list[0]))

for i in range(m) :
    deli = box_list[i][2]
    if 0 not in town[box_list[i][0]-1:box_list[i][1]]:
        if min(town[box_list[i][0]-1:box_list[i][1]]) >= box_list[i][2] :
            pass
        else :
            deli = min(town[box_list[i][0]-1:box_list[i][1]])
        for x in range(box_list[i][0] - 1, box_list[i][1] - 1):
            town[x] -= deli
    else :
        deli = 0
    result += deli

print(result)
