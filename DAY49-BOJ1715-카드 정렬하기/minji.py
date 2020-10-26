import sys
import heapq

def sol(lst):
    heapq.heapify(lst)
    if len(lst) == 1:
        return 0
    else:
        ans = 0
        while len(lst) > 1:
            a = heapq.heappop(lst)
            b = heapq.heappop(lst)
            tmp = a+b
            ans += tmp
            heapq.heappush(lst, tmp)
        return ans

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    lst = [0] * n
    for i in range(n):
        lst[i] = int(sys.stdin.readline())
    print(sol(lst))
