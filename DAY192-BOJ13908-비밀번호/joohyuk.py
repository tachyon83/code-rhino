import sys
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
nums = '0123456789'
knowns = [e for e in si().split()]
knowns = set(knowns)
hold = dict()
for num in nums:
    hold[num] = 0
ans = 0


def dfs(pos, cnt):
    global ans, n, m, knowns, hold
    if pos == n:
        flag = False
        for known in knowns:
            if not hold[known]:
                flag = True
                break
        if not flag:
            ans += 1
        return

    if n-pos > m:
        for num in nums:
            hold[num] += 1
            if num in knowns:
                m -= 1
                dfs(pos+1, cnt+1)
                m += 1
            else:
                dfs(pos+1, cnt)
            hold[num] -= 1
    else:
        for known in knowns:
            hold[known] += 1
            m -= 1
            dfs(pos+1, cnt+1)
            m += 1
            hold[known] -= 1


dfs(0, 0)
print(ans)
