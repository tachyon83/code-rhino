'''
나중에 다시 볼것..
이해 못하였음..
'''

def update_edge(edges: list, index: int):
    left_index = index * 2 + 1
    right_index = index * 2 + 2

    if left_index >= len(edges):
        return edges[index]

    left_max = update_edge(edges, left_index)
    right_max = update_edge(edges, right_index)

    total_max = max(right_max, left_max)

    edges[left_index] += (total_max - left_max)
    edges[right_index] += (total_max - right_max)

    return edges[index] + total_max


def get_sum(edges: list):
    update_edge(edges=edges, index=0)
    return sum(edges)



input()
edges = [0] + [int(edge) for edge in input().split()]
print(get_sum(edges))
