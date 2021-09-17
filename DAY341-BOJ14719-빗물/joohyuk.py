from collections import deque
import sys
si = sys.stdin.readline

h, w = [int(e) for e in si().split()]
arr = [int(e) for e in si().split()]
st, hold, rain = deque(), -1, 0

for i, e in enumerate(arr):
    if e >= hold:
        while st:rain += hold-st.pop()
        hold = e
    st.append(e)

if len(st) > 1:
    hold = st.pop()
    while st:
        curr = st.pop()
        if curr < hold:rain += hold-curr
        else:hold = curr
print(rain)
