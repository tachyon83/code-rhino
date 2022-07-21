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
var maxDepth = function(root) {
    return travel(1,root)
};

const travel=(depth,node)=>{
    if(!node)return depth-1
    return Math.max(travel(depth+1,node.left),travel(depth+1,node.right))
}
