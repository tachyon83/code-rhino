/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return createBST(nums, 0, nums.length-1);
    }
    
    // 정렬된 배열 -> BST 변환 메서드 생성
    // start == 배열의 시작 인덱스, end == 배열의 끝 인덱스
    public TreeNode createBST(int[] nums, int start, int end) {
        // 
        if (start > end) return null;
        
        // 정렬된 배열의 정중앙을 기준으로
        // 정중앙 == 부모 노드, 왼쪽 == 왼쪽 자식 서브트리, 오른쪽 == 오른쪽 자식 
        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = createBST(nums, start, mid-1);
        root.right = createBST(nums, mid+1, end);
        return root;
    }
}
