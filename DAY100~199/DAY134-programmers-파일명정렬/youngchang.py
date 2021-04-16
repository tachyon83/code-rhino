import re
def solution(files):
    lst = [] # (head, number, tail)
    for file in files:
        cnt = 0
        for c in file:
            if re.match('[^0-9]',c):
                cnt+=1
            else:
                break
        head = file[:cnt]
        cnt2 = 0
        for i in range(cnt, len(file)):
            if re.match('[0-9]',file[i]):
                cnt2+=1
            else:
                break
        number = file[cnt:cnt+cnt2]
        tail = file[cnt+cnt2:]
        lst.append((head, number, tail))

    lst.sort(key = lambda x : (x[0].lower(),int(x[1])))
    return [''.join(i) for i in lst]