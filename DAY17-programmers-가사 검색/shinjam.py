from collections import defaultdict

class Trie:
    def __init__(self):
        self.cnt = 0
        self.children = defaultdict(Trie)
        
def make_trie(words):
    ret = defaultdict(Trie)
    for word in words:
        root = ret[len(word)]
        cur = root
        for w in word:
            cur.children[w].cnt += 1
            cur = cur.children[w]
        root.cnt = sum(v.cnt for v in root.children.values())
    return ret
    
def count(query):
    if query[0] == '?':
        root, query = trie_r[len(query)], query[::-1]
    else:
        root = trie[len(query)]
    
    cur = root
    for q in query:
        if q == '?': 
            return cur.cnt
        cur = cur.children[q]
    return 1

        
def solution(words, queries):
    global trie, trie_r
    ans = []
    trie = make_trie(words)
    trie_r = make_trie(map(lambda x:x[::-1], words))

    for query in queries:
        ans.append(count(query))
    return ans
