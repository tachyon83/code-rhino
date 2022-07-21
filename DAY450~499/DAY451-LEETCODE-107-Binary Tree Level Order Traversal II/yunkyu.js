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
 * @return {number[][]}
 */
const levelOrderBottom = function(root) {
    if(!root) return []; // root가 null일시 빈 배열 반환
    const arr = [];
    const q = []; 
    q.push(root);
    while(q.length) { 
        const num = q.length; // 현재 레벨의 노드 수
        const a = []; // 현재 레벨의 노드들
        for(let i = 0; i < num; i++){
            const node = q.shift(); // 큐를 pop
            a.push(node.val);
            if(node.left) q.push(node.left); // left child가 있으면 
            if(node.right) q.push(node.right); // right child가 있으면
        }
        arr.push(a);
    }
    
    arr.reverse(); // top-down level이기 때문에 reverse로 bottom-up level로 전환한다
    return arr;
};
