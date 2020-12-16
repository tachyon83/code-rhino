import sys
def solve(n,k,t):
    temp = sum(t[:k])
    ans = temp
    for i in range(k,n):
        temp += t[i]
        temp -= t[i-k]
        if temp > ans:
            ans = temp
    return ans if n != k else temp
if __name__ == "__main__":
    n, k = map(int,sys.stdin.readline().split())
    t = list(map(int,sys.stdin.readline().split()))
    print(solve(n,k,t))
