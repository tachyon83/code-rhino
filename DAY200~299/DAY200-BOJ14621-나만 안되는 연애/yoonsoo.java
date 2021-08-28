import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	static class Node{
		int a;
		int b;
		int dis;
		public Node(int a, int b, int dis) {
			super();
			this.a = a;
			this.b = b;
			this.dis = dis;
		}
		
		
	}
	
	static String gender[];
	static Node info[];
	static int num[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		String tmp[] = br.readLine().split(" ");
		
		gender = new String[n+1];
		info = new Node[m];
		
		for(int i = 1 ; i<=tmp.length;i++) {
			gender[i] = tmp[i-1];
		}

		num = new int[n+1];
		for(int i = 1 ; i <= n ;i++) {
			num[i] = i;
		}
		
		for(int i  = 0 ; i < m ; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int dis = Integer.parseInt(st.nextToken());
			
			info[i] = new Node(a, b, dis);
		}
		
		Arrays.sort(info,new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return Integer.compare(o1.dis, o2.dis);
			}
			
		});
		
		int ans = 0;
		int cnt = 0;
		for(int i = 0 ; i < info.length; i++) {
			Node meeting = info[i];
			
			if(getParent(meeting.a) != getParent(meeting.b) && !gender[meeting.a].equals( gender[meeting.b])) {
				union(meeting.a, meeting.b);
				ans += meeting.dis;
				cnt++;
			}
			
		}
		
		if(cnt == n-1) {
			System.out.println(ans);
		}else {
			System.out.println(-1);
		}
		
	}
	
	
	public static int getParent(int x) {
		if(num[x] == x) return x;
		
		
		return getParent(num[x]);
		
	}
	
	public static void union(int a,int b) {
		a = getParent(a);
		b = getParent(b);
		
		if(a < b) {
			num[b] = a;
			
		}else {
			num[a]= b;
		}
		
		
	}
	

	
	
	
}
