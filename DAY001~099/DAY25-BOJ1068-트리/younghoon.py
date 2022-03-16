import sys
node_count = int(sys.stdin.readline())
nodes = list(map(int, sys.stdin.readline().split()))
to_delete = int(sys.stdin.readline())
tree = {}

for i in range(node_count):
    if i == to_delete or nodes[i] == to_delete:
        continue
    if nodes[i] in tree:
        tree[nodes[i]].append(i)
    else:
        tree[nodes[i]]= [i]

result = 0
if -1 in tree:
    que=[-1]
else:
    que=[]
while que:
    node = que.pop()
    if node not in tree:
        result+=1
    else:
        que+=tree[node]
print(result)









