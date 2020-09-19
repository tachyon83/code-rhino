class Trie():
    head = dict()
    def add(self, word):
        curr = self.head
        for ch in word:
            curr.setdefault(ch,[0,{}])
            curr[ch][0] +=1
            curr = curr[ch][1]
    
    def search(self, word):
        curr = self.head
        result = 0
        for ch in word:
            # print(ch)
            result += 1
            if curr[ch][0] == 1:
                break
            curr = curr[ch][1]
        return result


def solution(words):
    dictionary = Trie()
    for word in words:
        dictionary.add(word)
    
    result = 0
    for word in words:
        result += dictionary.search(word)

    return result
