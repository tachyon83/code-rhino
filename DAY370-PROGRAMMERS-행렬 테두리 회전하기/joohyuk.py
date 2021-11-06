def solution(rows, columns, queries):
    board,num,big,mn=[],1,10001,0
    for i in range(rows):
        row=[]
        for j in range(columns):
            row.append(num)
            num+=1
        board.append(row)
    
    dr,dc,dir=[0,1,0,-1],[1,0,-1,0],0
    
    def rot(cr,cc,coords,v):
        rs,cs,re,ce=coords
        nonlocal dir,mn
        mn=min(mn,v)
        if cr==rs and cc==cs and v:
            board[cr][cc]=v
            return
        while 1:
            nr,nc=cr+dr[dir],cc+dc[dir]
            if rs<=nr<=re and cs<=nc<=ce:break
            dir=(dir+1)%4

        temp=board[cr][cc]
        board[cr][cc]=v
        return rot(nr,nc,coords,temp)
    
    answer = []
    for query in queries:
        query,mn=[v-1 for v in query],big
        rot(query[0],query[1]+1,query,board[query[0]][query[1]])
        answer.append(mn)

    return answer
