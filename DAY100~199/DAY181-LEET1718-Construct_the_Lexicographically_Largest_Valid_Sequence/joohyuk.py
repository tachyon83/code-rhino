import sys
si = sys.stdin.readline

n, j = int(si()), 0
nums, vis = [e for e in range(n, 0, -1)], [False for _ in range(n)]
ans, pos = [0 for _ in range(2*n-1)], dict()


def backtrack(i):
    global n, nums, ans, pos
    if i >= 2*n-1:
        return True
    if i not in pos:
        for idx in range(n):
            if not vis[idx]:
                ans[i] = nums[idx]
                vis[idx] = True
                if i+nums[idx] >= 2*n-1:
                    return False
                pos[i+nums[idx]] = nums[idx]
                if backtrack(i+1):
                    return True
                vis[idx] = False
                del pos[i+nums[idx]]
        return False
    else:
        ans[i] = nums[i]
        backtrack(i+1)


backtrack(0)
print(*ans)
