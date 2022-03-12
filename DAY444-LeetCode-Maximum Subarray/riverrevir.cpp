class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], tempMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tempMax = max(nums[i], tempMax+nums[i]);
            ans = max(tempMax, ans);
        }
        return ans;
    }
};
