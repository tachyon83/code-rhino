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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var isSubtree = function(root, subRoot) {
  return solve(root, subRoot)
}

const solve = (t, subRoot) => {
  let flag = check(t, subRoot)
  if (flag) return flag
  if (t.left) flag = solve(t.left, subRoot)
  if (flag) return flag
  if (t.right) flag = solve(t.right, subRoot)
  return flag
}

const check = (t1, t2) => {
  if (!t1 && !t2) return true
  if (!t1 && t2) return false
  if (t1 && !t2) return false
  if (t1.val !== t2.val) return false
  return check(t1.left, t2.left) && check(t1.right, t2.right)
}
