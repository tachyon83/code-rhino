#include <bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = NULL;
         right = NULL;
      }
};
void inord(TreeNode *root){
   if(root != NULL){
      inord(root->left);
      cout << root->val << " ";
      inord(root->right);
   }
}
class Solution {
public:
   TreeNode* solve(string s, int& idx){
      if (idx >= s.size())
         return NULL;
      string num = "";
      while (idx < s.size() && s[idx] != '(' && s[idx] != ')') {
         num += s[idx];
         idx++;
      }
      TreeNode* node = new TreeNode(stoi(num));
      if (idx < s.size() && s[idx] == '(') {
         idx++;
         node->left = solve(s, idx);
         idx++;
         if (idx < s.size() && s[idx] == '(') {
            idx++;
            node->right = solve(s, idx);
            idx++;
         }
      }
      return node;
   }
   TreeNode* str2tree(string s) {
      int idx = 0;
      TreeNode* temp = new TreeNode(-1);
      return solve(s, idx);
   }
};
main(){
   Solution ob;
   TreeNode *root = ob.str2tree("4(2(3)(1))(6(5))");
   inord(root);
}
