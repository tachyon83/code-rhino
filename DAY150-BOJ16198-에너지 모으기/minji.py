import sys

def sol(lst, n):
    if n == 3:
        return lst[0] * lst[2]
    else:
        ans = 0
        for i in range(1, n-1):
            val = lst[i-1] * lst[i+1]
            val_lst = lst[:i] + lst[i+1:]
            re_lst = val + sol(val_lst, n-1)
            if ans < re_lst:
                ans = re_lst
        return ans

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))

    print(sol(lst, n))
