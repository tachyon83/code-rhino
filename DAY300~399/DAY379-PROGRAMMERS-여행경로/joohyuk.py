from collections import deque
import sys
si = sys.stdin.readline


def solution(tickets):
    path = deque(['ICN'])
    answer = []

    def DFS(tickets):
        nonlocal path,answer

        if not len(tickets):answer.append(list(path))
        else:
            tickets_copy = tickets[:]
            for ticket in tickets:
                if list(path)[-1] == ticket[0]:
                    path.append(ticket[1])
                    tickets_copy.remove(ticket)
                    DFS(tickets_copy)
                    path.pop()
                    tickets_copy.append(ticket)

    DFS(tickets)
    return min(answer)
