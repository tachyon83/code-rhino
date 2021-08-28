import sys
from collections import defaultdict

trees = defaultdict(int)
total = 0

for line in sys.stdin:
    trees[line.rstrip()] += 1
    total += 1

trees_sorted = sorted(trees.keys())
for tree in trees_sorted:
    print('{} {:0.4f}'.format(tree, trees[tree]/total*100))

