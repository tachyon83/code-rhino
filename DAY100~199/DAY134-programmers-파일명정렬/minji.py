import re
def solution(files):
    i = [re.split(r"([0-9]+)", f) for f in files]
    s_i = sorted(i, key = lambda x:(x[0].lower(), int(x[1])))
    return ["".join(i) for i in s_i]
