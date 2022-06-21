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
 * @return {string}
 */
const tree2str = function(root) {
    if(!root) {
        return "";
    }
    let str = `${root.val}`
    
    if(root.right) { // right child가 있으면 left, right 둘 다 표시
        str += `(${tree2str(root.left)})(${tree2str(root.right)})`;
    } 
    else if(root.left) str += `(${tree2str(root.left)})`; // left child만 있을 때
    
    return str;
};
