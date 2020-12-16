def solution():
    n =  int(input())
    arr = list(map(int, input().split()))
    removing_node = int(input())
    adj_list = [[] for _ in range(n)]
    for i in range(n):
        parent_node = arr[i]
        if parent_node == -1:
            root = i
            continue
        if parent_node == removing_node:
            continue
        if i == removing_node:
            continue
        adj_list[parent_node].append(i)
    # print(adj_list)
    
    def post_order(node, removing_node):
        if node == removing_node:
            return 0
        if not len(adj_list[node]):
            return 1
        ret = 0
        for nxt in adj_list[node]:
            ret += post_order(nxt, removing_node)
        return ret
    return post_order(root, removing_node)        

if __name__ == "__main__":
    print(solution())
