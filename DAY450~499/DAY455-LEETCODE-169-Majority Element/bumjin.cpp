class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for(size_t i = 1;i<nums.size();++i)
        {
            if(count==0)
            {
                major = nums[i];
                ++count;
            }
            else if(nums[i]==major)
                ++count;
            else
                --count;
        }
        return major;
    }
};
