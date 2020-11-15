n, c = map(int,input().split())
m = int(input())
town = [c] * (n-1)
result = 0

box_list = [list(map(int, input().split())) for _ in range(m)]
box_list.sort(key=lambda box_list: (box_list[1], box_list[0]))

for i in range(m) :
    deli = box_list[i][2]
    for x in range(box_list[i][0]-1,box_list[i][1]-1) :
        if town[x] >= box_list[i][2] :
            town[x] -= deli
        elif town[x] == 0 :
            deli = 0
        else :
            deli = town[x]
            town[x] = 0
    result += deli

print(result)
