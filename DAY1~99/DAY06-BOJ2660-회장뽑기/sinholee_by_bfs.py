'''
1년전에 풀었던 문제.... 이렇게 이상하게도 풀었구나 싶어서 공유합니다.
저도 이거 어떤 로직이었는지 기억이 안나는데 궁금하시다고 하면 다시 분석해서 설명해보도록 하겠습니다.
'''

N = int(input())
linked_list = [[] for _ in range(N + 1)]
score_list = [0] * (N + 1)
while True:
    node_1, node_2 = map(int, input().split())
    if node_1 == -1 and node_2 == -1:
        break
    linked_list[node_1].append(node_2)
    linked_list[node_2].append(node_1)
for i in range(1, N+1):
    visited = [0] * (N + 1)
    my_queue = []
    depth = 0
    my_queue.append(i)
    check = False
    while True:
        if check:
            break
        # 방문표시를 한다, 이때 이전에 방문을 했으면 밑에 포문에서 이미 append하지 않았기 때문에 지금 방문표시하는 것이 맞다.
        for node_idx in range(len(my_queue)):
            v = my_queue.pop(0)  # 내가 가지고 있는 후보군 중 맨 첫번째 애를 팝 한뒤
            visited[v] = 1
            if 0 not in visited[1:]:
                score_list[i] = depth
                check = True
                break
            for linked_node in linked_list[v]:
                if visited[linked_node] == 0:
                    my_queue.append(linked_node)

        depth += 1

count = 0
small_score = min(score_list[1:])
result = []
for s in range(len(score_list[1:])):
    if small_score == score_list[s+1]:
        count += 1
        result.append(s+1)

print(small_score, count)
print(' '.join(map(str, result)))

