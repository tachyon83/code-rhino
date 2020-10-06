k = int(input())
arr = list(map(str, input().split()))
BIGNUM = "9876543210"
SMALLNUM = "0"

def is_correct(a, b, symbol):
    if symbol == "<":
        return a < b
    return a > b


def get_min_nums(k, constant):
    s = ""
    for i in range(k+1):
        s += constant[9-i]
    return s


def get_max_nums(k):
    s = ""
    for i in range(k+1):
        s += BIGNUM[i]
    return s

    '''
    첫번째 질문
    
    아래 perm함수에서 is_correct함수를 callback이라는 인자로 받았는데 인자로 받지 않는 스타일이 더 깔끔할까요?
    같은 맥락으로, get_min_nums(k, constant) 와 같이 상수를 인자로 받는게 더 좋은스타일일까요, 
    get_max_nums(k) 처럼 상수는 그냥 부모스코프에 있는 변수를 문맥상 끌어다 쓰는 스타일이 더 깔끔할까요?

    함수형 프로그래밍의 규칙 중에 모든 자원은 인자로 받아야 완전함수라고 해서 일단 받긴했는데, 인자가 많아지니 
    오히려 가독성이 떨어지고 코드를 읽기 힘들어질거같다는게 개인적인 생각입니다.
    다른분들은 어떻게 생각하시는지 궁금합니다.

    두번째 질문 
    callback이라는 이름 말고 마땅한 변수 명 뭐가 좋을까요...
    전체적으로 변수명도 피드백 주실 부분 있으면 달게 받겠습니당.

    '''
def perm(depth, visited, target, num_length, res, symbols_arr, is_max, callback):  
    if depth == num_length:
        return res
    min_value = BIGNUM
    max_value = SMALLNUM
    for i in range(num_length):
        if visited[i]:
            continue
        if depth and not callback(res[-1], target[i], symbols_arr[depth-1]):
            continue
        visited[i] = 1
        temp = perm(depth+1, visited, target, num_length, res+target[i], symbols_arr, is_max, callback)
        if is_max:
            max_value = max(temp, max_value)
        else:
            min_value = min(temp, min_value)
        visited[i] = 0
    return max_value if is_max else min_value


print(perm(0, [0] * (k+1), get_max_nums(k), k+1, "", arr, True, is_correct))
print(perm(0, [0] * (k+1), get_min_nums(k, BIGNUM), k+1, "", arr, False, is_correct))

