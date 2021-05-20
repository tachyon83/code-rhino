import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int num[];
	static int tree[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		num = new int[n];
		tree = new int[n*4];
		for(int i = 0 ; i< n ; i++) {
			num[i] = Integer.parseInt(br.readLine());
		}
		
		int order[][] = new int[m][2];
		int ans[][] = new int[m][2];
		mininit(0, num.length-1, 1);
		for(int i = 0 ; i < m ;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			order[i][0] = a;
			order[i][1] = b;
			
			ans[i][0] = min(0, n-1, 1, a-1, b-1);
		}
		
		maxinit(0, num.length-1, 1);
		for(int i = 0 ; i < m ;i++) {
			ans[i][1] = max(0, n-1, 1, order[i][0]-1, order[i][1]-1);
		}
		
		for(int i = 0 ; i < m ;i++) {
			System.out.println(ans[i][0]+" "+ans[i][1]);
		}
		
		
	

	}
	
	public static int mininit(int start,int end,int node) {
		if(start == end) return tree[node] = num[start];
		
		int mid = (start+end)/2;
		
		
		return tree[node] = Math.min(mininit(start, mid, node*2), mininit(mid+1, end, (node*2+1)));
	}
	
	public static int maxinit(int start,int end,int node) {
		if(start == end) return tree[node] = num[start];
		
		int mid = (start+end)/2;
		
		
		return tree[node] = Math.max(maxinit(start, mid, node*2), maxinit(mid+1, end, node*2+1));
	}
	
	
	public static int max(int start,int end,int node,int left,int right) {
		
		// 범위 안에 없다.
		if(left > end || right < start) return 0;
		
		if(left <= start && end <= right ) return tree[node];
		
		int mid = (start+end)/2;
		
		return Math.max(max(start,mid,node*2,left,right), max(mid+1,end,node*2+1,left,right));
	}
	
	
	public static int min(int start,int end,int node,int left,int right) {
		
		// 범위 안에 없다.
		if(left > end || right < start) return Integer.MAX_VALUE;
		
		if(left <= start && end <= right ) return tree[node];
		
		int mid = (start+end)/2;
		
		return Math.min(min(start,mid,node*2,left,right), min(mid+1,end,node*2+1,left,right));
	}
	
	
}
