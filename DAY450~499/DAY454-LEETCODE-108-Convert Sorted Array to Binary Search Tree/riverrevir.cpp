class Solution {
public:
    TreeNode* makeTree(vector<int>& nums,int left,int right){
        if(left>right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = makeTree(nums,left,mid-1);
        newNode->right = makeTree(nums,mid+1,right);
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums,0,nums.size()-1);
    }
};
