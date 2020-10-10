n = int(input())    
arr = sorted(list(map(int, input().split())))

l,r = 0, n-1
answer = [arr[l], arr[r]]
res = arr[l]+arr[r]
while l < r:
    curr = arr[l] + arr[r]
    if abs(res) > abs(curr):
        res = curr
        answer = [arr[l], arr[r]]
    if curr > 0:
        r -= 1
    else:
        l += 1
            
print(" ".join(map(str, sorted(answer))))
