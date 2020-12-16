from collections import deque
def solution(s):
    min_length = 9999
    for jump in range(1, len(s)//2 + 2):
        words = deque()
        for index in range(0, len(s), jump):
                word = s[index:index+jump]
                words.append(word)
        
        result = [words.popleft()]
        count = 1
        while words:
            curr = words.popleft()
            if result[-1] == curr:
                count += 1
                if not words:
                    prev = result.pop()
                    result.append(str(count) + prev)
            else:
                if count != 1:
                    prev = result.pop()
                    result.append(str(count) + prev)
                result.append(curr)
                count = 1
        # print(result)
        min_length = min(min_length, len(''.join(result)))
    return min_length
