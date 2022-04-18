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

const dfs = node => {
    let ret = []
    if (node.left) dfs(node.left).forEach(e => ret.push('' + node.val + e))
    if (node.right) dfs(node.right).forEach(e => ret.push('' + node.val + e))
    if (!ret.length) ret.push('' + node.val)
    return ret
}

var sumNumbers = function (root) {
    let ans = 0
    dfs(root).forEach(e => {
        ans += parseInt(e)
    })
    return ans
};
