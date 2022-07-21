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
const maxDepth = function(root) {
    if(!root) return 0; // node가 없으면 
    let depth = 1; 
    const leftDepth = maxDepth(root.left);
    const rightDepth = maxDepth(root.right);
    depth += Math.max(leftDepth,rightDepth); // Max(left sub tree's depth, right sub tree's depth)
    return depth;
};
