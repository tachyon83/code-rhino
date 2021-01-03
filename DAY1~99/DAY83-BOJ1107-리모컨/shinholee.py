from collections import deque

def solution(target, n, rest_nums):
    q = deque([(-1, 0, True), (100,0, False)])
    visited = [0]* 1000000
    visited[100] = 1

    
    res = -1
    while q:
        num, cnt, is_appendable = q.popleft()
        # print(num)
        if num == target:
            res = cnt
            break
        if num == -1:
            q.append((0, 1, False))
            visited[0] = 1
            for rest_num in rest_nums:
                new_num = rest_num
                if 0<= new_num < 1000000 and not visited[new_num]:
                    visited[rest_num] = 1
                    q.append((new_num, cnt+1, True))
            continue
        if 0<= num+1 < 1000000 and not visited[num+1]:
            visited[num+1] = 1
            q.append((num+1, cnt+1 , False))
        if 0<= num-1 < 1000000 and not visited[num-1]:
            visited[num-1] = 1
            q.append((num-1, cnt+1, False))
        if is_appendable:
            for rest_num in rest_nums:
                new_num = num * 10 + rest_num
                if 0<= new_num < 1000000 and not visited[new_num]:
                    visited[rest_num] = 1
                    q.append((new_num, cnt+1, True))
    return res


if __name__ == "__main__":
    
    target = int(input())
    n = int(input())
    missing_nums = [*map(int, input().split())]
    rest_nums = [0,1,2,3,4,5,6,7,8,9]
    rest_nums = [*filter(lambda x: x not in missing_nums, rest_nums)]
    print(solution(target,n,rest_nums))
