#include <iostream>
using namespace std;
struct Node{
   int key;
   struct Node* left, *right;
};
Node *newNode(char k){
   Node *node = new Node;
   node->key = k;
   node->right = node->left = NULL;
   return node;
}
bool isLeafNode(Node *node){
   if (node == NULL)
      return false;
   if (node->left == NULL && node->right == NULL)
      return true;
   return false;
}
int findLeftLeavesSum(Node *root){
   int sum = 0;
   if (root != NULL){
      if (isLeafNode(root->left))
         sum += root->left->key;
      else
         sum += findLeftLeavesSum(root->left);
      sum += findLeftLeavesSum(root->right);
   }
   return sum;
}
int main(){
   struct Node *root = newNode(5);
   root->left = newNode(4);
   root->right = newNode(6);
   root->left->left = newNode(2);
   root->left->right = newNode(1);
   root->right->left = newNode(9);
   root->right->right = newNode(7);
   cout<<"The sum of left leaves of the tree is "<<findLeftLeavesSum(root);
   return 0;
}
