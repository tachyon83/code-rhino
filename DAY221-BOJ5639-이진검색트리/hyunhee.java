import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {

	static class Node {
		int num;
		Node left, right;

		public Node(int num) {
			this.num = num;
		}

		public Node(int num, Node left, Node right) {
			this.num = num;
			this.left = left;
			this.right = right;
		}

		public void insert(int n) {
			if (n < this.num) {
				if (this.left == null) {
					this.left = new Node(n);
				} else {
					this.left.insert(n);
				}
			} else {
				if (this.right == null) {
					this.right = new Node(n);
				} else {
					this.right.insert(n);
				}
			}
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Node root = new Node(Integer.parseInt(br.readLine()));
		String next;
		while (true) {
			next = br.readLine();
			if (next == null || "".equals(next)) {
				break;
			}
			root.insert(Integer.parseInt(next));
		}

		postOrder(root);

	}

	private static void postOrder(Node root) {
		if (root == null) {
			return;
		}
		postOrder(root.left);
		postOrder(root.right);
		System.out.println(root.num);

	}

}