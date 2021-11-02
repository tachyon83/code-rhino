import sys
si = sys.stdin.readline

k=int(si())
pr,pc=[int(e) for e in si().split()]

if k==1:
    if pr==1 and pc==1:
        print('1 1')
        print('-1 1')
    elif pr==2 and pc==1:
        print('1 1')
        print('1 -1')
    elif pr==1 and pc==2:
        print('-1 1')
        print('1 1')
    else:
        print('1 -1')
        print('1 1')
else:
    if pr==1 and pc==1:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 1 3 2')
        print('-1 1 2 2')
    elif pr==2 and pc==1:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 1 3 2')
        print('1 -1 2 2')
    elif pr==1 and pc==2:
        print('4 4 5 5')
        print('4 3 3 5')
        print('-1 1 3 2')
        print('1 1 2 2')
    elif pr==2 and pc==2:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 -1 3 2')
        print('1 1 2 2')
    elif pr==3 and pc==1:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 3 2 2')
        print('1 1 -1 2')
    elif pr==3 and pc==2:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 3 -1 2')
        print('1 1 2 2')
    elif pr==4 and pc==1:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 3 2 2')
        print('1 1 2 -1')
    elif pr==4 and pc==2:
        print('4 4 5 5')
        print('4 3 3 5')
        print('1 3 2 -1')
        print('1 1 2 2')
    elif pr==1 and pc==3:
        print('5 5 4 4')
        print('-1 5 2 4')
        print('1 2 2 3')
        print('1 1 3 3')
    elif pr==1 and pc==4:
        print('-1 2 5 5')
        print('2 2 3 5')
        print('1 3 3 4')
        print('1 1 4 4')
    elif pr==2 and pc==3:
        print('4 4 5 5')
        print('4 -1 2 5')
        print('1 2 2 3')
        print('1 1 3 3')
    elif pr==2 and pc==4:
        print('2 -1 4 4')
        print('2 2 3 4')
        print('1 3 3 5')
        print('1 1 5 5')
    elif pr==3 and pc==3:
        print('2 2 4 4')
        print('2 3 -1 4')
        print('1 3 3 5')
        print('1 1 5 5')
    elif pr==3 and pc==4:
        print('2 2 -1 4')
        print('2 3 4 4')
        print('1 3 3 5')
        print('1 1 5 5')
    elif pr==4 and pc==3:
        print('2 2 4 4')
        print('2 3 4 -1')
        print('1 3 3 5')
        print('1 1 5 5')
    elif pr==4 and pc==4:
        print('2 2 4 -1')
        print('2 3 4 4')
        print('1 3 3 5')
        print('1 1 5 5')
