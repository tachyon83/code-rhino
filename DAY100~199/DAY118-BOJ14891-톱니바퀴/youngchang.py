import sys
from collections import deque

        
def read_in():
    for line in sys.stdin:
        yield line.replace('\n', '')
        
def main():
    reader = read_in()
    g1 = deque(map(int, next(reader)))
    g2 = deque(map(int, next(reader)))
    g3 = deque(map(int, next(reader)))
    g4 = deque(map(int, next(reader)))
    gs = [g1, g2, g3, g4]
    
    K = int(next(reader))
    for _ in range(K):
        i, d = map(int, next(reader).split())
        
        c1 = [g1[2], g2[6]]
        c2 = [g2[2], g3[6]]
        c3 = [g3[2], g4[6]]
        
        orders = []
        if i == 1:
            orders.append((1, d))
            if sum(c1) == 1:
                orders.append((2, -d))
                if sum(c2) == 1:
                    orders.append((3, d))
                    if sum(c3) == 1:
                        orders.append((4, -d))
        elif i == 2:
            orders.append((2, d))
            if sum(c1) == 1:
                orders.append((1, -d))
            if sum(c2) == 1:
                orders.append((3, -d))
                if sum(c3) == 1:
                    orders.append((4, d))
        elif i == 3:
            orders.append((3, d))
            if sum(c2) == 1:
                orders.append((2, -d))
                if sum(c1) == 1:
                    orders.append((1, d))
            if sum(c3) == 1:
                orders.append((4, -d))
        elif i == 4:
            orders.append((4, d))
            if sum(c3) == 1:
                orders.append((3, -d))
                if sum(c2) == 1:
                    orders.append((2, d))
                    if sum(c1) == 1:
                        orders.append((1, -d))
        
        for i, d in orders:
            gs[i - 1].rotate(d)
            
    answer = 0
    m = 1
    for i in range(4):
        answer += gs[i][0] * m
        m *= 2
    print(answer)

main()