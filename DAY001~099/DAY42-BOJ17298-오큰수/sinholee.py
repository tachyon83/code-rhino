def soluion(n, arr):
    stack = []
    res = []
    for i in range(n-1, -1, -1):
        
        while stack:
            poped = stack.pop()
            if arr[i] < poped:
                res.append(poped)
                stack.append(poped)
                break
        else:
            res.append(-1)

        stack.append(arr[i])
    answer = " ".join(map(str, res[::-1]))
    return answer


if __name__ == "__main__":
    n = int(input())
    arr = [*map(int, input().split())]
    print(soluion(n, arr))
