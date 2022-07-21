class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solved(nums, 0, nums.size()-1);
    }
    TreeNode* solved(vector<int>& nums, int start, int end){
        if(start > end) {
            return nullptr;
        }
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid], solved(nums, start, mid-1), solved(nums, mid+1, end));
        return root;
    }
};
