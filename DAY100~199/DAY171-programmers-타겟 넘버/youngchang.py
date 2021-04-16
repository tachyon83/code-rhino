import numpy as np
def solution(numbers,target):
    n = np.array(numbers)
    lst = []
    h = len(numbers)
    w = 2**h
    for i in range(1,h+1):
        lst.extend(([1]*int(w/2**i) + [-1]*int(w/2**i))*(2**(i-1)))
    m = np.array(lst).reshape([h,w])
    return sum(1 for i in n@m if i == target)