import sys

sys.setrecursionlimit(100000)

# 재귀를 이용한 분할 정복
def preorder(in_start, in_end, post_start, post_end):
    if in_start > in_end or post_start > post_end:
        return
    
    # 후위 순회의 결과 끝이 서브트리의 루트이므로, parents로 선언
    parents = postorder[post_end]
    print(parents, end = " ")
    
    # 중위 순회에서 루트의 좌우로 자식들이 갈라지므로, 각각 left와 right로 선언
    left = position[parents] - in_start
    right = in_end - position[parents]
    
    # left, right로 나눠 재귀 분할 정복으로 트리를 추적하며 전위 순회를 구현
    preorder(in_start, in_start+left-1, post_start, post_start+left-1) # 왼쪽 노드
    preorder(in_end-right+1, in_end, post_end-right, post_end-1) # 오른쪽 노드

n = int(sys.stdin.readline())
inorder = list(map(int, sys.stdin.readline().split()))
postorder = list(map(int, sys.stdin.readline().split()))

# 후위 순회의 끝값이 중위 순회의 어떤 인덱스에 위치한지 확인하기 위해 중위 순회값들의 인덱스를 저장
position = [0 for _ in range(n+1)]
for i in range(n):
    position[inorder[i]] = i;

# 중위 순회, 후위 순회 모두 0부터 n-1까지 노드를 탐색하므로, 해당 값을 넣고 전위 순회 시행
preorder(0, n-1, 0, n-1)
