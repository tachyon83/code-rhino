def check(a,b):
    if len(a)!=len(b):return False
    i=-1
    for e in b:
        i+=1
        if e=='*':continue
        if a[i]!=e:return False
    return True
        
def solution(user_id, banned_id):
    nums=[]
    
    for bid in banned_id:
        temp=[]
        
        for i,uid in enumerate(user_id):
            if check(uid,bid):temp.append(i)
        nums.append(temp)
        
    ansSet=set()
    
    def play(i,s):
        nonlocal banned_id, nums, ansSet
        if i==len(banned_id):
            ansSet.add(tuple(sorted(s)))
            return
        if not len(nums[i]):
            play(i+1,s)
            return
        for e in nums[i]:
            if e in s:continue
            s.add(e)
            play(i+1,s)
            s.remove(e)
        
        
    def solve():play(0,set())
        
    
    solve()
    return len(ansSet)
