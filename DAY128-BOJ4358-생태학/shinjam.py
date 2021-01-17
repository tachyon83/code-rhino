from collections import defaultdict

trees = defaultdict(int)
while True:
    tree = input()
    if not tree:
        break
    trees[tree] + 1
tree_names = trees.keys()
n = len(trees)
for tree in sorted(tree_names):
    print(f"{tree} {trees[tree]/n*100:.4f}")
