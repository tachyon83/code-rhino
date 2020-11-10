import sys

def sol(lst, bomb):
    stack = []
    bomb_l = bomb[-1]
    length = len(bomb)

    for c in lst:
        stack.append(c)
        a = stack[-len(bomb):]
        if c == bomb_l and ''.join(stack[-length:]) == bomb:
            del stack[-length:]

    ans = ''.join(stack)

    return "FRULA" if ans == '' else ans

if __name__ == "__main__":
    lst = sys.stdin.readline().strip()
    bomb = sys.stdin.readline().strip()
    print (sol(lst, bomb))
