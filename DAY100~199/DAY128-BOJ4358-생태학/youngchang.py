import sys
from collections import Counter


trees = [line.rstrip() for line in sys.stdin]
c = Counter(trees)
N = len(trees)
for tree, cnt in sorted(c.items()):
    print('{} {:0.4f}'.format(tree, cnt * 100 / N))