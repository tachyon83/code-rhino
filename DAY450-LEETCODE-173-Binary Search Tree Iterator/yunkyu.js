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
 */
const BSTIterator = function(root) {
    this.arr = []; 
    this.inOrder(root);
};

BSTIterator.prototype.inOrder = function(root) { // arr에 inorder 순회 순서를 집어넣는다.
    if(!root) return;
    
    this.inOrder(root.left);
    this.arr.push(root.val);
    this.inOrder(root.right);
}

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    const val = this.arr.shift(); // 가장 앞의 원소를 빼서 반환
    return val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    if(this.arr.length > 0) return true; // 남아있는 원소가 있다면 true
    else return false; // 없다면 false
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
