/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
const sortedArrayToBST = function(nums) {
    if(nums.length === 0) return null;
    const rootIdx = Math.floor(nums.length/2); // 중간 idx가 root의 idx
    const root = nums[rootIdx]; // root를 찾는다
    const tree = new TreeNode(root); 
    tree.left = sortedArrayToBST(nums.slice(0,rootIdx)); // left sub tree 연결
    tree.right = sortedArrayToBST(nums.slice(rootIdx+1,nums.length)) // right sub tree 연결
    return tree;
};
