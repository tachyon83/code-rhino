#실행한 결괏값 [4,2,5,4,0]이(가) 기댓값 [3,2,4,1,0]와(과) 다릅니다.
#0번째, 2번째, 3번째 값이 잘못 나오는 이유:
#추측인데, 길이별로 트라이정렬을 실패해서 그런것 같음
#예: 0번쨰 인덱스 3이 나와야되는데 4가 나옴
#fro??의 경우 frodo, front frost 이렇게 3이 나와야되는데
#frozen을 포함시켜서 4가 나오고
#2번째 인덱스를보면 4가 나와야되는데 5가 나옴
#fr??? frozen이 또 포함된것 같음.
#3번째 인덱스의 경우
#fro??? 1이 나와야되는데 4가 나옴
#5글자 짜리 fro??들이 포함된 값이라 추측됨
#디버깅을 도와주세요

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
        if query[0] != "?":
            # print(trie_by_length[len(query)].length)
            result.append(trie_by_length[len(query)].search(query))
        else:
            # print(r_trie_by_length[len(query)].length)
            query = query[::-1]
            result.append(r_trie_by_length[len(query)].search(query))
    return result


class Trie():
    head = dict()
    length = 0
    #트라이에 추가시킴, value의 0번째에 sub-tree?의 갯수를 업데이트 시킴. 1번째는 traversing을 위한 다음 노드
    def add(self, word):
        # global length
        curr = self.head
        for ch in word:
            curr.setdefault(ch,[0,{}])
            curr[ch][0] +=1
            curr = curr[ch][1]
        # self.length += 1
    
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
            
            
