class Solution {
public:
    int sumNumbers(TreeNode* root, int initVal = 0) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            //leaf node
            return initVal + root->val;
        }
        
        int sum = 0;
        sum += sumNumbers(root->left, (initVal+root->val)*10) + sumNumbers(root->right, (initVal+root->val)*10);
        
        return sum;
    }
};
