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
const dfs = (curr, acc) => {
    if(!curr) return 0; // node가 없으면
    if(!curr.right && !curr.left) { // leaf 일시 현재 노드 value 누적
        return acc + curr.val;
    }
    
    const nextSum = (acc + curr.val) * 10; // depth가 증가하면 누적값의 자릿수를 늘려준다.
    return dfs(curr.left, nextSum) + dfs(curr.right, nextSum); // left sub tree의 누적값과 right sub tree의 누적값을 합한다.
}

const sumNumbers = function(root) {
    return dfs(root, 0);
};
