n = int(input())
s = [[0] * 3 for i in range(26)]
def preorder(a):
    print(a, end="")
    if s[ord(a) - 65][1] != ".":
        preorder(s[ord(a) - 65][1])
    if s[ord(a) - 65][2] != ".":
        preorder(s[ord(a) - 65][2])
def inorder(a):
    if s[ord(a) - 65][1] != ".":
        inorder(s[ord(a) - 65][1])
    print(a, end="")
    if s[ord(a) - 65][2] != ".":
        inorder(s[ord(a) - 65][2])
def postorder(a):
    if s[ord(a) - 65][1] != ".":
        postorder(s[ord(a) - 65][1])
    if s[ord(a) - 65][2] != ".":
        postorder(s[ord(a) - 65][2])
    print(a, end="")
for i in range(n): 
    ro, le, ri = map(str, input().split())
    ro_ = ord(ro) - 65
    s[ro_][0], s[ro_][1], s[ro_][2] = ro, le, ri
preorder("A")
print()
inorder("A")
print()
postorder("A")
