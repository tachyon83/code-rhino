import sys
input = sys.stdin.readline

w,h=map(int,input().split())
walls=[list(map(int,input().split())) for _ in range(h)]
rnums=[[0]*w for _ in range(h)]#방번호 지도 
rnum=1#방번호
d=[(0,-1),(-1,0),(0,1),(1,0)]
for y in range(h):
    for x in range(w):
        if rnums[y][x]:
            continue
        st=[(y,x)]
        while st:
            nowY,nowX=st.pop()
            rnums[nowY][nowX]=rnum
            wall=walls[nowY][nowX]
            for i in range(4):
                if not wall&(1<<i):
                    nextY,nextX=nowY+d[i][0],nowX+d[i][1]
                    if not rnums[nextY][nextX]:
                        st.append((nextY,nextX))
        rnum+=1
rnum-=1
print(rnum)
roomSize=[0]+[sum(row.count(i) for row in rnums)for i in range(1,rnum+1)]
print(max(roomSize))

neighbor=set()
for y in range(h):
    for x in range(w):
        if x!=w-1 and rnums[y][x]!=rnums[y][x+1]:
            neighbor.add((rnums[y][x],rnums[y][x+1]))
        if y!=h-1 and rnums[y][x]!=rnums[y+1][x]:
            neighbor.add((rnums[y][x],rnums[y+1][x]))

print(max(roomSize[a]+roomSize[b] for a,b in neighbor ))
