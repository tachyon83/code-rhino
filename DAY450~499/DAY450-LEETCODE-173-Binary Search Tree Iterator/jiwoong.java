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
class BSTIterator {

    private TreeNode root;
    private List<Integer> inOrder;
    private Iterator<Integer> it;

    private void inorder(TreeNode root){
        if(root!=null){
            inorder(root.left);
            inOrder.add(root.val);
            inorder(root.right);
        }
    }

    public BSTIterator(TreeNode root) {
        this.root = root;
        this.inOrder = new ArrayList<>();
        inorder(this.root);
        it = this.inOrder.iterator();
    }

    public int next() {
        return this.it.next();
    }

    public boolean hasNext() {
        if(this.it.hasNext()) return true;
        return false;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */