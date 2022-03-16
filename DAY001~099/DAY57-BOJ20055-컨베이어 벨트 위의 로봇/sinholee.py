from collections import deque
def solution(n, k, container_belt):
    DEBUG = False
    robot_queue = deque([])
    visited = [0] * (2*n)
    up_idx = 0
    res = 0
    while k>0:
        # 1
        up_idx = (up_idx +(2 * n -1)) %(2 * n)
        down_idx = (up_idx + n-1) % (2*n) 
        if DEBUG:
            print("===============================")
            print('up_idx', up_idx)
            print('down: ', down_idx)
        flag = False
        if visited[down_idx]:
            visited[down_idx] = 0
            
        # 2
        rnd = len(robot_queue)
        for _ in range(rnd):
            idx = robot_queue.popleft()
            if idx == down_idx:
                continue
            temp_idx = (idx + 1) % (2 * n)
            if not visited[temp_idx] and container_belt[temp_idx]:
                container_belt[temp_idx] -= 1
                if not (temp_idx == down_idx):
                    robot_queue.append(temp_idx)
                    visited[temp_idx] = 1
                visited[idx] = 0
                if not container_belt[temp_idx]:
                    k -= 1
            else:
                robot_queue.append(idx)
        # 3
        if not visited[up_idx] and container_belt[up_idx]:
            robot_queue.append(up_idx)
            container_belt[up_idx] -= 1
            visited[up_idx] = 1

