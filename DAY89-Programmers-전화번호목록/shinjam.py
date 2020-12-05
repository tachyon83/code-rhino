from itertools import combinations

def solution(phone_book):
    for a, b in combinations(phone_book, 2):
        if a[0] == b[0] and a in b or b in a:
            return False
    return True
