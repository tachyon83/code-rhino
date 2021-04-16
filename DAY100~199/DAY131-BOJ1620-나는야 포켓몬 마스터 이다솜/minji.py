import sys

def sol():

    if p_ans.isdigit():
        print(p_list[int(p_ans) - 1])
    else:
        print(p_dic[p_ans])

if __name__ == "__main__":
    p_dic = {}
    n, m = map(int, sys.stdin.readline().split())
    p_list = []
    for i in range(n):
        p = sys.stdin.readline().rstrip()
        p_list.append(p)
        p_dic[p] = i+1

    for _ in range(m):
        p_ans = sys.stdin.readline().rstrip()
        sol()
