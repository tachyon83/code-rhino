# Root node를 찾아주는 함수
def find(x):
    if x == parent[x]:
        return x
    else:
        root_x = find(parent[x])
        parent[x] = root_x
        return parent[x]

# y의 Root 노드가 x의 Root 노드와 같지 않으면 
# y의 Root 노드가 x의 Root 노드의 자식이 되도록 하는 함수
def union(x,y):
    root_x = find(x)
    root_y = find(y)

    if root_x!=root_y:
        parent[root_y] = root_x
        number[root_x] +=number[root_y]

test_cases = int(input())

for _ in range(test_cases):
    parent = dict()
    number = dict()

    f = int(input())

    for _ in range(f):
        x,y = input().split(" ")
        
        if x not in parent:
            parent[x] = x
            number[x] = 1
        if y not in parent:
            parent[y] = y
            number[y] = 1
        
        union (x,y)
        print(number[find(x)])
