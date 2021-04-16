class UnionFind:
    def __init__(self, size):
        self.parent = [x for x in range(size)]
        self.rank = [0]*(size)

    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x, y):
        parent_x = self.find(x)
        parent_y = self.find(y)
        if parent_x != parent_y:
            if self.rank[parent_x] > self.rank[parent_y]:
                self.parent[parent_y] = parent_x
            elif self.rank[parent_x] < self.rank[parent_y]:
                self.parent[parent_x] = parent_y
            else:
                self.parent[parent_y] = parent_x
                self.rank[parent_x] += 1

def main():
    N, M = map(int, input().split())
    know = list(map(int, input().split()))
    if know.pop(0) == 0:
        print(M)
        return
    know = [i - 1 for i in know]
    
    answer = 0
    parties = []
    for _ in range(M):
        people = list(map(int, input().split()))
        if people.pop(0) == 0:
            answer += 1
            continue
        people = [i - 1 for i in people]
        parties.append(people)
    
    djs = UnionFind(N)
    for i, j in zip(know[:-1], know[1:]):
        djs.union(i, j)
    
    for p in parties:
        for i, j in zip(p[:-1], p[1:]):
            djs.union(i, j)

    a = know[0]
    for p in parties:
        b = p[0]
        if djs.find(a) != djs.find(b):
            answer += 1
    
    print(answer)

main()