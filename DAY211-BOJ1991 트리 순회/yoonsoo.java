import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	static class Node{
		String value;
		Node left;
		Node right;
		
		Node(String value) {
			this.value = value;
		}
		
	}
	
	static class Tree{
		public static Node root;
		
		public static void create(String value,String left,String right) {
			if(root == null) {
				root = new Node(value);
				//좌우 값이 있는경우 노드 생성
				if(!left.equals(".")) {
					root.left = new Node(left);
				}
				if(!right.equals(".")) {
					root.right = new Node(right);
				}
				
			}else {
				//초기 상태가 아니라면 루트 노드 생성 이후 만들어진 노드 중 어떤건지를 찾아야함
				search(root,value,left,right);
			}
			
		}
		
		public static void search(Node node, String value, String left, String right) {
			if(node == null) {
				return;
			}else if(node.value.equals(value)) {
				if(!left.equals(".")) {
					node.left = new Node(left);
				}
				if(!right.equals(".")) {
					node.right = new Node(right);
				}
			}else {
				//왼쪽 재귀 탐색
				search(node.left, value, left, right);
				//오른쪽 재귀 탐색
				search(node.right, value, left, right);
				
			}
			
			
		}
		
		public static void pre(Node node) {
			if(node != null && !node.value.equals(".")) {
				System.out.print(node.value);
				if(node.left != null) pre(node.left);
				if(node.right != null) pre(node.right);
			}
		}
		public static void in(Node node) {
			if(node != null && !node.value.equals(".")) {
				if(node.left != null) in(node.left);
				System.out.print(node.value);
				if(node.right != null) in(node.right);
			}
		}
		public static void post(Node node) {
			if(node != null && !node.value.equals(".")) {
				if(node.left != null) post(node.left);
				if(node.right != null) post(node.right);
				System.out.print(node.value);
			}
			
		}
		
		
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		Tree tree = new Tree();
		for(int i = 0; i < n ;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			String c = st.nextToken();
			tree.create(a, b, c);
		}
		
		tree.pre(tree.root);
		System.out.println();
		tree.in(tree.root);
		System.out.println();
		tree.post(tree.root);
		
		
	}
	

	
	
}
