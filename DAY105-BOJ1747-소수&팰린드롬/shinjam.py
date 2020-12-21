import sys
sys = sys.stdin.readline

def is_prime(num):
    for i in range(2, int(N**.5)+1):
        if N % i == 0:
            return False
    return True

def is_pal(num):
    str_num = str(num)
    size = len(str_num)
    for i in range(size//2):
        if str_num[i] != str_num[size-1-i]:
            return False
    return True

N = int(input())

while True:
    if is_prime(N) and is_pel(N):
        break
    N += 1
print(N)
