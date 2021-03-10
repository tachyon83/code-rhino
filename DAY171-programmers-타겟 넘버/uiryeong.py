answer = 0
def dfs(numbers, target, sum_num, idx):
    global answer
    if idx >= len(numbers):
        if sum_num == target:
            answer += 1
        return
        
    
    dfs(numbers, target, sum_num + numbers[idx], idx+1)
    dfs(numbers, target, sum_num - numbers[idx], idx+1)
    
    return

def solution(numbers, target):
    
    dfs(numbers, target, 0, 0)
    return answer
