###힙으로 다시풀기
import sys
from bisect import bisect_left
def sol():
    if cnt == 1:
        return num
    if cnt % 2 == 0: #even
        print(min(num_list[cnt//2-1], num_list[cnt//2]))
    else:
        print(num_list[cnt//2])

if __name__ == "__main__":
    num_list = []
    n = int(sys.stdin.readline())

    cnt = 1
    for _ in range(n):
        num = int(sys.stdin.readline())
        idx = bisect_left(num_list, num)
        num_list.insert(idx, num)
        sol()
        cnt += 1
