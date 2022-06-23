class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        return treeSearch(root);
    }
    
    private int treeSearch(TreeNode node) {
        if (node == null) {
            return 0;
        }

        return leftTreeSearch(node.left) + treeSearch(node.right);
    }

    private int leftTreeSearch(TreeNode node) {
        if (node == null) {
            return 0;
        }

        if (node.left == null && node.right == null) {
            return node.val;
        }

        return leftTreeSearch(node.left) + treeSearch(node.right);
    }
}
