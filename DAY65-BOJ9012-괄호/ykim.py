n = int(input())
def check(nums):
    stack = []
    for i in nums:
        if i == "(":
            stack.append(i)
        else:
            if not stack:
                print("NO")
                return
            else:
                stack.pop()
    if not stack:
        print("YES")
        return
    else:
        print("NO")
        return

for _ in range(n):
    nums = input()
    check(nums)
