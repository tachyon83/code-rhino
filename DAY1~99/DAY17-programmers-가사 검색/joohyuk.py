import sys
sys.setrecursionlimit(100001)


class Trie:
    def __init__(self):
        self.parent = 0
        self.hold = dict()
        self.finished = dict()

    def add(self, word, lwd):
        temp = self
        for ch in word:
            if ch not in temp.hold:
                temp.hold[ch] = Trie()
                temp.hold[ch].parent = temp
            temp = temp.hold[ch]
        temp.finished[lwd] = 1
        while temp.parent:
            temp = temp.parent
            if lwd not in temp.finished:
                temp.finished[lwd] = 0
            temp.finished[lwd] += 1

    def solve(self, word, lwd):
        temp, i = self, 0
        for ch in word:
            if ch == '?':
                if lwd not in temp.finished:
                    return 0
                return temp.finished[lwd]
            elif ch in temp.hold:
                i += 1
                temp = temp.hold[ch]
            else:
                return 0


def solution(words, queries):
    answer, T, RT = [], Trie(), Trie()
    for word in words:
        T.add(word, len(word))
        RT.add(word[::-1], len(word))
    for query in queries:
        if query[0] == '?':
            query = query[::-1]
            answer.append(RT.solve(query, len(query)))
        else:
            answer.append(T.solve(query, len(query)))
    return answer
