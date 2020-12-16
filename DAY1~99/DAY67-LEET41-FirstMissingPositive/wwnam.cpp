class Solution {
public:
    bool check[301] = { false, };
    int firstMissingPositive(vector<int>& nums) {
        int numSize = nums.size();
        for (int i = 0; i < numSize; i++) {
            if (nums[i] >= 0 && nums[i] <= numSize) {
                check[nums[i]] = true;
            }
        }

        int ans = 0;
        for (int i = 1; i <= numSize; i++) {
            if (!check[i]) {
                ans = i;
                break;
            }
        }
        if (!ans) {
            return numSize + 1;
        }
        else {
            return ans;
        }
    }
};