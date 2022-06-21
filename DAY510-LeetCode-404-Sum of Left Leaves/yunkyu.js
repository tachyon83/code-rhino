/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
const sumOfLeftLeaves = function(root) {
    if(!root) { // 노드가 없으면 종료
        return 0;
    }
    
    let sum = 0;
    if(root.left) { // left child가 존재할 시
        if(!root.left.left && !root.left.right) sum += root.left.val; // left child가 leaf node이면
        else sum+= sumOfLeftLeaves(root.left);
    }
    if(root.right) sum += sumOfLeftLeaves(root.right); // right child가 존재할 시
    
    return sum;
};
