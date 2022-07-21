var majorityElement = function(nums) {
    nums.sort((a,b)=>a-b)
    const counter={}
    for(const num of nums){
        if(!(num in counter))counter[num]=0
        counter[num]++
    }
    const ans=Object.keys(counter).map(key=>[counter[key],key])
    ans.sort((a,b)=>b[0]-a[0])
    return ans[0][1]
};
