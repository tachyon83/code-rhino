
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int inorder[];
	static int postorder[];
	static int inOrderidx[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int n = Integer.parseInt(br.readLine());
		inorder = new int[n+1];
		postorder = new int[n+1];
		inOrderidx = new int[n+1];
		
		String tmp[] = br.readLine().split(" ");
		for(int i = 0 ; i < n ;i++) {
			inorder[i] = Integer.parseInt(tmp[i]);
			
		}
		tmp = br.readLine().split(" ");
		for(int i = 0 ; i < n ;i++) {
			postorder[i] = Integer.parseInt(tmp[i]);
			
		}
		
		for(int i = 0 ;i < n;i++) {
			inOrderidx[inorder[i]] = i;
		}
		
		
	
		preorder(0, n-1, 0, n-1);
		
		
	}
	
	public static void preorder(int instart,int inend,int poststart,int postend) {
		if(instart > inend || poststart > postend ) return;
		int root = postorder[postend];
		System.out.print(root+" ");
		
		int inroot = inOrderidx[root];
		int left = inroot -instart;
		
		//왼쪽영역
		preorder(instart, inroot-1, poststart, poststart+left-1);
		//오른쪽영역
		preorder(inroot+1, inend, poststart+left, postend-1);
		

	}
	
	
}
