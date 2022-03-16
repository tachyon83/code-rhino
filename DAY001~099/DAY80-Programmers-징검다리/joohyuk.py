def solution(distance, rocks, n):
    s,e=0,distance
    rocks.sort()
    while s<=e:
        cnt,pos=0,0
        mid=(s+e)//2
        for rock in rocks:
            if mid>rock-pos:
                cnt+=1
            else:
                pos=rock
        if cnt<=n:
            ans=mid
            s=mid+1
        else:
            e=mid-1
    return ans
