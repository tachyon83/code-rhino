import sys,heapq
si=sys.stdin.readline

t=int(si())
while t:
    t-=1
    pq1,pq2,nums=[],[],dict()
    cnt=int(si())
    for _ in range(cnt):
        order,v=[e for e in si().split()]
        v=int(v)
        if order=='I':
            heapq.heappush(pq1,-v)
            heapq.heappush(pq2,v)
            if v not in nums:nums[v]=0
            nums[v]+=1
        else:
            if v==1:
                while pq1 and not nums[-pq1[0]]:heapq.heappop(pq1)
                if pq1:
                    nums[-pq1[0]]-=1
                    heapq.heappop(pq1)
            else:
                while pq2 and not nums[pq2[0]]:heapq.heappop(pq2)
                if pq2:
                    nums[pq2[0]]-=1
                    heapq.heappop(pq2)
    

    if not pq1:print('EMPTY')
    else:
        while pq1 and not nums[-pq1[0]]:heapq.heappop(pq1)
        if not pq1:print('EMPTY')
        else:
            mx=-pq1[0]
            while pq2 and not nums[pq2[0]]:heapq.heappop(pq2)
            mn=pq2[0]
            print(mx,mn)
