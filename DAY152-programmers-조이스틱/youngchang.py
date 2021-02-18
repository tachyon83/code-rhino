def solution(name):
    up_short = list('BCDEFGHIJKLMN')
    down_short = list('OPQRSTUVWXYZ')
    down_short.reverse()
    dd = {'A':0}
    for i in up_short:
        dd[i] = up_short.index(i)+1
    for i in down_short:
        dd[i] = down_short.index(i)+1
        
    up_down_cnt = 0
    for i in list(name):
        up_down_cnt += dd[i]
        
    
    import re
    binary = re.sub('[^A]','1',name)
    binary = re.sub('A','0',binary)
    num = list(binary)
    move_lst = []
    for move_right in range(len(num)):
        num = list(binary)
        num[:move_right+1] = (move_right+1)*'0'
        cursur = 0
        cursur += move_right
        move = move_right
        while sum(list(map(int,num)))!=0:
            cursur-=1
            move+=1
            if num[cursur]=='1':
                num[cursur] = 0
        move_lst.append(move)
    left_right_cnt = min(move_lst)
    
    return up_down_cnt + left_right_cnt