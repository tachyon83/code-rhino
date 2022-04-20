class Solution {
public:
    int cal(TreeNode* root)
    {
        if(root!=nullptr)
        {
            return max(cal(root->left),cal(root->right))+1;
        }
        return 0;
    }
    
    int maxDepth(TreeNode* root) {
        return cal(root);
    }
};
