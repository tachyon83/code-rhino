from collections import deque

N, K = map(int, input().split())
A = list(map(int, input().split()))
robots = [0]*N*2
belt = deque(range(2*N))

ans = 0
while True:
    ans += 1
    belt.rotate(1) # 1. 벨트회전
    robots[belt[N-1]] = 0 # 로봇 내리기
    
    for i in range(N-2, 0, -1): # 2. 로봇 이동
        ci, ni = belt[i], belt[i+1]
        if robots[ci] and not robots[ni] and A[ni]:
            robots[ci] = 0
            robots[ni] = 1
            A[ni] -= 1
            
    robots[belt[N-1]] = 0 # 로봇 내리기

    # 3. 로봇 올리기
    if A[belt[0]]:
        A[belt[0]] -= 1
        robots[belt[0]] = 1
    
    # 4. 종료
    if A.count(0) >= K:
        break
print(ans)  
