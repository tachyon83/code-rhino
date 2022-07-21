count_0 = 0
count_1 = 0

def quad(n, li):
    global count_0, count_1

    li2 = set()

    for i in range(n):
        for j in range(n):
            li2.add(li[i][j])
    
    if li2 == {1}:
        count_1 += 1
        return
    elif li2 == {0}:
        count_0 += 1
        return
    else:
        quad(n//2, [x[:n//2] for x in li[:n//2]])
        quad(n//2, [x[n//2:] for x in li[:n//2]])
        quad(n//2, [x[:n//2] for x in li[n//2:]])
        quad(n//2, [x[n//2:] for x in li[n//2:]])
    

def solution(arr):
    quad(len(arr), arr)
    return [count_0, count_1]
