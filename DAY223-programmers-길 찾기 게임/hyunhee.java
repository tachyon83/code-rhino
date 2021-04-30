import java.util.Arrays;
import java.util.Comparator;

class Solution {
    int[][] answer;
    int total;
    
    class Node {
		int r;
		int c;
		int num;
		Node left;
		Node right;

		public Node(int r, int c, int num) {
			this.r = r;
			this.c = c;
			this.num = num;
		}

		public void insert(Node node) {
			if (node.r < this.r) {
				if (this.left == null) {
					this.left = node;
				} else {
					this.left.insert(node);
				}
			} else {
				if (this.right == null) {
					this.right = node;
				} else {
					this.right.insert(node);
				}
			}
		}
	}
    
    public int[][] solution(int[][] nodeinfo) {
        int len = nodeinfo.length;
		answer = new int[2][len];
		Node[] nodes = new Node[len];
		for (int i = 0; i < len; i++) {
			nodes[i] = new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1);
		}

		Arrays.sort(nodes, new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				if (o1.c > o2.c) {
					return -1;
				}
				if (o1.c < o2.c) {
					return 1;
				}
				if (o1.r > o2.r) {
					return 1;
				}
				return -1;
			}
		});

		Node root = nodes[0];
		for (int i = 1; i < len; i++) {
			root.insert(nodes[i]);
		}

		preOrder(root);
		total = 0;
		postOrder(root);
        
        return answer;
    }
    
    private void preOrder(Node root){
        if(root==null){
            return;
        }
        answer[0][total++] = root.num;
        preOrder(root.left);
        preOrder(root.right);
    }
    
    private void postOrder(Node root){
        if(root==null){
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        answer[1][total++] = root.num;
    }
}