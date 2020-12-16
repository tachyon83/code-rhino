import sys

def sol(ps):
    ans = 0
    for i in ps:
        if i == "(":
            ans += 1
        else:
            ans -= 1
            if ans < 0:
                break
    if ans != 0:
        return "NO"
    else:
        return "YES"

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for i in range(t):
        ps = list(map(str, sys.stdin.readline().strip()))
        print(sol(ps))
