def solution(words, queries):
    result = []
    #물음표가 앞에 붙었는지 뒤에 붙었는지를 분별하기위에 트라이를 정방향, 거꾸로 방향 두개 만듬
    trie_by_length = [Trie() for i in range(10001)]
    r_trie_by_length = [Trie() for i in range(10001)]
    #각 트라이에 워드별 길이에 맞춰 추가시킴 
    for word in words:
        trie_by_length[len(word)].add(word)
        r_trie_by_length[len(word)].add(word[::-1])
    for query in queries:
        if query[0] =="?" and query[len(query)-1] =="?":
            print
            result.append(trie_by_length[len(query)].size)
        elif query[0] != "?":
            result.append(trie_by_length[len(query)].search(query))
        else:
            query = query[::-1]
            result.append(r_trie_by_length[len(query)].search(query))
    return result


class Trie():
    def __init__(self):
        self.head = dict()
        self.size = 0
    #트라이에 추가시킴, value의 0번째에 sub-tree?의 갯수를 업데이트 시킴. 1번째는 traversing을 위한 다음 노드
    def add(self, word):
        curr = self.head
        for ch in word:
            curr.setdefault(ch,[0,{}])
            curr[ch][0] +=1
            curr = curr[ch][1]
        self.size+=1

    def search(self, word):
        curr = self.head
        for i in range(len(word)):
            #키가 없는경우 찾고자 하는것이 없는것이므로 리턴0
            #다음키가 ?인 경우 value의 1번쨰 (subtree의 갯수를 리턴함)
            if word[i] in curr.keys():
                if word[i+1] == '?':
                    return curr[word[i]][0]
                curr = curr[word[i]][1]
            else:
                return 0
