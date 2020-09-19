from collections import defaultdict
import sys 
sys.setrecursionlimit(10**8)

class Node:
    def __init__(self, cnt = 0):
        self.cnt = cnt
        self.children = defaultdict(Node)
        
def add(root, word, idx = 0):
    if idx == len(word): 
        return
    root.children[word[idx]].cnt += 1
    add(root.children[word[idx]], word, idx + 1)

def check(root, word, idx = 0):
    if idx == len(word): 
        return idx
    if root.children[word[idx]].cnt == 1 :
        return idx + 1
    return check(root.children[word[idx]], word, idx + 1)


        
def solution(words):
    root = Node()
    ret = 0
    for word in words:
        add(root, word)
    for word in words:
        ret += check(root, word)
    
    return ret
