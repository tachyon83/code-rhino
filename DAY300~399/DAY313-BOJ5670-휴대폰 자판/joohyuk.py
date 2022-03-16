import sys
si = sys.stdin.readline

trie = dict()


def add(s):
    curr = trie
    for e in s:
        if e not in curr:
            curr[e] = dict()
        curr = curr[e]
    curr[0] = 1


n, ln, trie, words = 0, 0, dict(), []


def reset():
    global trie, words
    trie, words = dict(), []


for line in sys.stdin:
    if not n:
        n, cnt = int(line), 0
        reset()
    else:
        ln += 1
        line = line[:-1]
        add(line)
        words.append(line)

    if ln == n:
        for word in words:
            curr, hold = trie, ''
            i, sz = 0, len(word)
            for i in range(sz):
                if i == len(hold):
                    hold += word[i]
                    curr = curr[word[i]]
                    i += 1
                    cnt += 1

                key_arr = list(curr.keys())
                while 0 not in key_arr and len(key_arr) == 1:
                    hold += key_arr[0]
                    i += 1
                    curr = curr[key_arr[0]]
                    key_arr = list(curr.keys())

        print('%.2f' % (cnt/ln))
        n, ln = 0, 0
