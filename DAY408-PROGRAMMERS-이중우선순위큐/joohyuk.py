from collections import deque


def solution(operations):
    dq = deque()
    for operation in operations:
        operation = operation.split()
        op, v = operation[0], int(operation[1])
        if op == 'I':
            if not dq:dq.append(v)
            else:
                if v <= dq[0]:dq.appendleft(v)
                else:dq.append(v)
            dq.sort()
        else:
            if dq:
                if v == 1:dq.pop()
                else:dq.popleft()

    if dq:
        if len(dq) == 1:return [dq[0], dq[0]]
        else:return [dq[-1], dq[0]]
    return [0, 0]
