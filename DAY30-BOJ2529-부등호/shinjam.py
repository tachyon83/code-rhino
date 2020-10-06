N = int(input())
ops = list(input().split())
ret = []

def dfs(comp, i, history):
    if i == len(ops):
        ret.append(''.join(map(str, history)))
        return
    
    for n in range(10):
        if n in history:
            continue
        if ops[i] == '<' and comp < n:
            dfs(n, i + 1, [*history, n])
        elif ops[i] == '>' and comp > n:
            dfs(n, i + 1, [*history, n]) 

for n in range(10):
    dfs(n, 0, [n])
        
                
print(max(ret))
print(min(ret))
