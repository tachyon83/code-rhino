import sys
si=sys.stdin.readline

n,tree=int(si()),dict()

def preorder(a):
	if a=='.':return
	global tree
	print(a,end='')
	preorder(tree[a][0])
	preorder(tree[a][1])
	
def inorder(a):
	if a=='.':return
	global tree
	inorder(tree[a][0])
	print(a,end='')
	inorder(tree[a][1])
	
def postorder(a):
	if a=='.':return
	global tree
	postorder(tree[a][0])
	postorder(tree[a][1])
	print(a,end='')
	
for i in range(n):
	line=[e for e in si().split()]
	tree[line[0]]=[line[1],line[2]]

preorder('A')
print()
inorder('A')
print()
postorder('A')
