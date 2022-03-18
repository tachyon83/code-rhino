class Solution {
public:
    void genPerms(vector<vector<int> >& ans, vector<int>& nums, int genfrom) {
        if (genfrom == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = genfrom; i < nums.size(); ++i) {
            //swap number at genfrom with the number at i
            swap(nums[genfrom], nums[i]);
            genPerms(ans, nums, genfrom + 1);
            swap(nums[genfrom], nums[i]);
        }
    } 
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size(); ++i) {
            //set number to start with
            swap(nums[0], nums[i]);
            genPerms(ans, nums, 1);
            swap(nums[0], nums[i]);
        }
        
        return ans;
    }
};
