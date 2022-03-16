# 최대공약수 함수
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def solution(w, h):
    # 주어진 가로 격자와 세로 격자의 최대공약수 = 대각선이 지나가는 최소단위 격자 수
    div = gcd(w, h)
    # 전체 타일 수
    total_tile = w * h
    # 빠지는 타일 수 = 대각선이 지나가는 최소단위 격자 수 * (대각선이 닿는 타일 수)
    remove_tile = div * (w//div + h//div - 1)
    return total_tile - remove_tile
