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
const isEqual = (root, subRoot) => {
    if(!subRoot && !root) return true; // 더 이상 비교할 노드가 없을 때
    else if((!subRoot && root) || (subRoot && !root)) return false; // 한쪽이 하위 노드가 더 많다면 실패
    
    if(root.val !== subRoot.val) return false; // root와 subRoot의 value가 같지 않다면 실패
    
    // left subtree와 right subtree가 모두 같아야 한다.
    return isEqual(root.left, subRoot.left) && isEqual(root.right, subRoot.right);
}

const isSubtree = function(root, subRoot) {
    if(!root) return false; 
    
    let ret;
    
    if(root.val === subRoot.val){ // root value가 같다면 포함여부 검사
        ret = isEqual(root, subRoot);
    }
    
    ret |= isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot); // subtree가 포함되는 부분이 존재한다면 성공
    
    return ret;
};
