import sys
#sys.stdin = open('input.txt', 'r')
N = int(sys.stdin.readline())
height = []
for _ in range(N):
    height.append(list(map(int, sys.stdin.readline().split())))
height.sort()

def trap():
    volume = 0
    left, right = 0, len(height) - 1
    max_left, max_right = height[left][1], height[right][1]

    while left < right:
        max_left = max(height[left][1], max_left)
        max_right = max(height[right][1], max_right)

        if max_left <= max_right:
            volume += (max_left)* abs(height[left][0] - height[left+1][0])
            left += 1
        else:
            volume += (max_right)* abs(height[right][0] - height[right-1][0])
            right -= 1

    volume += max(max_right, max_left)
    return volume
print(trap())




