class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> answer = new ArrayList<>();
        if(root==null) return answer;

        Queue<TreeNode> Q = new LinkedList<>();
        Q.offer(root);

        while(!Q.isEmpty()){
            List<Integer> tmp = new ArrayList<>();
            int size = Q.size();

            for(int i=0;i<size;i++){
                TreeNode cur = Q.poll();
                tmp.add(cur.val);
                if(cur.left!=null) Q.offer(cur.left);
                if(cur.right!=null) Q.offer(cur.right);
            }
            answer.add(0,tmp);
        }
        return answer;
    }
}