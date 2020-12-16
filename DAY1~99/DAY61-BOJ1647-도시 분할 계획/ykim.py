def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]


def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


if __name__ == "__main__":
    n, m = map(int, input().split())  # 집의 개수, 길의 개수 입력받기
    graph = []
    for _ in range(m):  # 길 입력받기
        a, b, c = map(int, input().split())
        graph.append([c, a, b])

    parent = [0] * (n + 1)
    for i in range(1, n + 1):
        parent[i] = i

    # 간선 정렬
    graph.sort()

    # 크루스칼 수행
    selected = []  # 선택된 간선

    answer = 0
    for c, a, b in graph:
        if find_parent(a) != find_parent(b):
            union_parent(a, b)
            answer += c
            selected.append(c)

    # 마을을 두개로 분리하기 위해서 마지막 간선 제거
    answer -= selected.pop()

    # 출력
    print(answer)
