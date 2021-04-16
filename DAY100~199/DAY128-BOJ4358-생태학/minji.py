import sys
from collections import defaultdict

dic = defaultdict(int)

total = 0
while True:
    tree = sys.stdin.readline().strip()
    if not tree:
        break
    dic[tree] += 1
    total += 1

for t in sorted(dic.keys()):
    print('{0} {1:0.4f}'.format(t, dic[t]*100/total))
