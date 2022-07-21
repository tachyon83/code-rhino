import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

def traverse(inL, inR, postL, postR):

    if inL > inR or postL > postR:
        return

    ans.append(postorder[postR])

    seperateIdx = idxs[postorder[postR]]
    
    tmp = postL + seperateIdx - inL
    
    traverse(inL, seperateIdx - 1, postL, tmp - 1)
    traverse(seperateIdx + 1,  inR, tmp, postR - 1)


N = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
idxs = {}
ans = []

for i in range(len(inorder)):
    idxs[inorder[i]] = i

traverse(0, N - 1, 0, N - 1)

print(*ans)
