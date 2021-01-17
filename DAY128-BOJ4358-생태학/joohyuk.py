import sys
total = {0: 0}


class Trie:
    def __init__(self):
        self.hold = dict()
        self.cnt = 0

    def add(self, word):
        temp = self
        for ch in word:
            if ch not in temp.hold:
                temp.hold[ch] = Trie()
            temp = temp.hold[ch]
        temp.cnt += 1

    def search(self, word):
        temp = self
        for ch in word:
            if ch not in temp.hold:
                return 0
            temp = temp.hold[ch]
        if temp.cnt:
            return temp.cnt
        else:
            return 0

    def stat(self, comp):
        if self.cnt:
            print("%s %0.4f" % (comp, self.cnt/total[0]*100))

        keys = sorted(self.hold.keys())
        for e in keys:
            comp += e
            nxtTrie = self.hold[e]
            nxtTrie.stat(comp)
            comp = comp[:-1]


def main():
    root, t = Trie(), 0
    for line in sys.stdin:
        line = line.rstrip()
        root.add(line)
        total[0] += 1

    root.stat('')


if __name__ == '__main__':
    main()
