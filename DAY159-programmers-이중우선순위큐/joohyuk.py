import heapq

def solution(operations):
    mn, mx = [], []
    d, i = [False for _ in range(len(operations))], 0
    for operation in operations:
        operation = operation.split()
        op, v = operation[0], int(operation[1])
        if op == 'I':
            heapq.heappush(mn, (v, i))
            heapq.heappush(mx, (-v, i))
            i += 1
        else:
            tmp = False
            if v == 1:
                while mx and d[mx[0][1]]:heapq.heappop(mx)
                if mx:tmp = heapq.heappop(mx)
            else:
                while mn and d[mn[0][1]]:heapq.heappop(mn)
                if mn:tmp = heapq.heappop(mn)
            if tmp:d[tmp[1]] = True
    while mn and d[mn[0][1]]:heapq.heappop(mn)
    while mx and d[mx[0][1]]:heapq.heappop(mx)
    if not mn and not mx:return [0, 0]
    if not mn:return [-mx[0][0], -mx[0][0]]
    if not mx:return [mn[0][0], mn[0][0]]
    return [-mx[0][0], mn[0][0]]
