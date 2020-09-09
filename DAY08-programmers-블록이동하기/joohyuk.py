from collections import deque


def solution(board):

    answer, q, sz, visited, flag = 0, deque(), len(board), set(), False
    q.append(((0, 0), (0, 1)))

    visited.add(((0, 0), (0, 1)))
    visited.add(((0, 1), (0, 0)))
    dx, dy, dr = [0, 1, 0, -1], [1, 0, -1, 0], [-1, 1]

    while q:
        answer += 1
        qs = len(q)
        for _ in range(qs):
            curr = q.popleft()
            curr1, curr2 = curr[0], curr[1]

            for i in range(4):
                n1x = curr1[0]+dx[i]
                n1y = curr1[1]+dy[i]
                n2x = curr2[0]+dx[i]
                n2y = curr2[1]+dy[i]

                if 0 <= n1x < sz and 0 <= n1y < sz and 0 <= n2x < sz and 0 <= n2y < sz:
                    if not board[n1x][n1y] and not board[n2x][n2y]:
                        if (n1x, n1y) == (sz-1, sz-1) or (n2x, n2y) == (sz-1, sz-1):
                            flag = True
                            break
                        if ((n1x, n1y), (n2x, n2y)) not in visited:
                            visited.add(((n1x, n1y), (n2x, n2y)))
                            visited.add(((n2x, n2y), (n1x, n1y)))
                            q.append(((n1x, n1y), (n2x, n2y)))

            if curr1[0] == curr2[0]:
                for i in range(2):
                    n1x, n1y = curr1[0], curr1[1]
                    n2x = curr1[0]+dr[i]
                    n2y = curr1[1]
                    checkx = n2x
                    checky = curr2[1]
                    if 0 <= n2x < sz and 0 <= n2y < sz:
                        if not board[n2x][n2y] and not board[checkx][checky]:
                            if (n2x, n2y) == (sz-1, sz-1):
                                flag = True
                                break
                            if ((n1x, n1y), (n2x, n2y)) not in visited:
                                visited.add(((n1x, n1y), (n2x, n2y)))
                                visited.add(((n2x, n2y), (n1x, n1y)))
                                q.append(((n1x, n1y), (n2x, n2y)))

                for i in range(2):
                    n1x = curr2[0]+dr[i]
                    n1y = curr2[1]
                    n2x, n2y = curr2[0], curr2[1]
                    checkx = n1x
                    checky = curr1[1]
                    if 0 <= n1x < sz and 0 <= n1y < sz:
                        if not board[n1x][n1y] and not board[checkx][checky]:
                            if (n1x, n1y) == (sz-1, sz-1):
                                flag = True
                                break
                            if ((n1x, n1y), (n2x, n2y)) not in visited:
                                visited.add(((n1x, n1y), (n2x, n2y)))
                                visited.add(((n2x, n2y), (n1x, n1y)))
                                q.append(((n1x, n1y), (n2x, n2y)))

            else:
                for i in range(2):
                    n1x, n1y = curr1[0], curr1[1]
                    n2x = curr1[0]
                    n2y = curr1[1]+dr[i]
                    checkx = curr2[0]
                    checky = n2y
                    if 0 <= n2x < sz and 0 <= n2y < sz:
                        if not board[n2x][n2y] and not board[checkx][checky]:
                            if (n2x, n2y) == (sz-1, sz-1):
                                flag = True
                                break
                            if ((n1x, n1y), (n2x, n2y)) not in visited:
                                visited.add(((n1x, n1y), (n2x, n2y)))
                                visited.add(((n2x, n2y), (n1x, n1y)))
                                q.append(((n1x, n1y), (n2x, n2y)))

                for i in range(2):
                    n1x = curr2[0]
                    n1y = curr2[1]+dr[i]
                    n2x, n2y = curr2[0], curr2[1]
                    checkx = curr1[0]
                    checky = n1y
                    if 0 <= n1x < sz and 0 <= n1y < sz:
                        if not board[n1x][n1y] and not board[checkx][checky]:
                            if (n1x, n1y) == (sz-1, sz-1):
                                flag = True
                                break
                            if ((n1x, n1y), (n2x, n2y)) not in visited:
                                visited.add(((n1x, n1y), (n2x, n2y)))
                                visited.add(((n2x, n2y), (n1x, n1y)))
                                q.append(((n1x, n1y), (n2x, n2y)))
            if flag:
                break
        if flag:
            break

    return answer
