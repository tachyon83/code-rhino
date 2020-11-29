import sys
 
N,M=map(int,sys.stdin.readline().split())
#앱
m=list(map(int,sys.stdin.readline().split()))#메모리
c=list(map(int,sys.stdin.readline().split()))#비활성화 비용
result=[10001]*(M+1)
result[0]=0
#M = 확보할 메모리
for i in range(N):
    rm=m[i]#해당 메모리를 제거할때
    for j in range(M,-1,-1):
        if result[j]!=10001:#해당 값이있다면
            if j+rm>=M:#목표 메모리보다 크다면
                if result[M]>result[j]+c[i]:#기존 보다 비용 더 작게 든다면
                    result[M]=result[j]+c[i]
            else:#목표 메모리보다 작다면
                if result[j+rm]>result[j]+c[i]:#기존보다 비용이 작게든다면 갱신시켜준다.
                    result[j+rm]=result[j]+c[i]
 
print(result[M])
