gears = []
for _ in range(4):
    gears.append(list(input()))
K = int(input())
orders = [list(map(int, input().split())) for _ in range(K)]

def rotation(number, direction):
    global gears

    if direction == 1:
        gears[number] = [gears[number][-1]] + gears[number][:-1]
    else:
        gears[number] = gears[number][1:] + [gears[number][0]]

while orders:
    number, direction = orders.pop(0)
    number -= 1

    right, left = gears[number][2], gears[number][6]
    rotation(number, direction)
    for idx, nxt in enumerate(range(number+1, 4)):
        if right != gears[nxt][6]:
            right = gears[nxt][number]
            if idx % 2:
                rotation(nxt, direction)
            else:
                rotation(nxt, -direction)
        else:
            break

    for idx, nxt in enumerate(range(number-1, -1, -1)):
        if left != gears[nxt][2]:
            left = gears[nxt][6]
            if idx % 2:
                rotation(nxt, direction)
            else:
                rotation(nxt, -direction)
        else:
            break

total = [2**i for i in range(4) if gears[i][0] == '1']
print(sum(total))
