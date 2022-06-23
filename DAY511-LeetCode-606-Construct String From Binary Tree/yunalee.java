class Solution {
    public String tree2str(TreeNode root) {
        if (root == null) {
            return "";
        }

        String result = root.val + "";

        String left = tree2str(root.left);
        String right = tree2str(root.right);

        if (left == "" && right == "") {
            return result;
        }
        else if (left == "") {
            return result + "()" + "(" + right + ")";
        }
        else if (right == "") {
            return result + "(" + left + ")";
        }
        else {
            return result + "(" + left + ")" + "(" + right + ")";
        }
    }
}
