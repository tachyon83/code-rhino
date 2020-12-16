l, c = map(int, input().split())
arr = sorted([*input().split()])
visited = [0] * c
def dfs(prev, depth, vowel, consonant, res):
    if depth == l:
        if vowel >= 1 and consonant >= 2:
            print(res)
        return
    for i in range(prev, c):
        if visited[i]:
            continue
        visited[i] = 1
        if arr[i] in ('a', 'e', 'i', 'o', 'u'):
            dfs(i, depth+1, vowel+1, consonant, res +arr[i])
        else:
            dfs(i, depth+1, vowel, consonant+1, res +arr[i])
        visited[i] = 0

dfs(0, 0, 0, 0, "")
