    n, M = map(int, input().split())
    t = int(input()))
    box = [list(map(int, input().split())) for i in range(t)]


    box.sort(key=lambda x:x[1]) 

    answer = 0  # 최대 박스 수
    remain = [M] * (n + 1) 

    for i in range(t):
        temp = c  # c개를 옮길 수 있다고 가정
        for j in range(box[i][0], box[i][1]):
            temp = min(temp, remain[j])
        temp = min(temp, box[i][2])
        for j in range(box[i][0], box[i][1]):
            remain[j] -= temp
        ans += temp

    print(ans)
