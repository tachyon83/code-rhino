import sys

def sol(lst):
    lst.sort()
    ans = 0
    for i in range(n):
        if ans+1 >= lst[i]:
            ans = ans + lst[i]
        else:
            break
    return ans+1

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))

    print(sol(lst))
