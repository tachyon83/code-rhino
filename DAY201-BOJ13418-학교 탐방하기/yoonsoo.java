

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
	
	

	static int num[];
	static Node list[];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		num = new int[n+1];
		list = new Node[m+1];
		int incline = 0;
		for(int i = 0 ; i < m+1;i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int dis = Integer.parseInt(st.nextToken());
			list[i] = new Node(a, b, dis);
			
			if(dis == 0) {
				incline++;
			}
		}

		num = new int[n+1];
		for(int i = 0 ; i <= n ;i++) {
			num[i] = i;
		}
		
		int min = 0;
		int max = 0;
		
		Arrays.sort(list,new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return Integer.compare(o2.dis, o1.dis);
			}
		});
		min = len();
		
		
		for(int i = 0 ; i <= n ;i++) {
			num[i] = i;
		}
		Arrays.sort(list,new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return Integer.compare(o1.dis, o2.dis);
			}
		});
		max = len();

		
	
		System.out.println(max-min);
	
	}
	
	public static int len() {
		int cnt =0;
		
		for(int i = 0 ; i <list.length;i++) {
			Node way = list[i];
			if(!find(way.a, way.b)) {
				union(way.a, way.b);
				if(way.dis == 0) {
					cnt++;
				}
			}
		}
		
		
		return (int)Math.pow(cnt, 2);
		
	}
	
	public static int getParent(int x) {
		if(num[x] == x )return x;
		
		return getParent(num[x]);
	}
	
	public static void union(int a,int b) {
		 a = getParent(a);
		 b = getParent(b);
		 
		 if(a < b) {
			 num[b] =a;
		 }else {
			 num[a] =b;
		 }
		 
	}
	
	public static boolean find(int a,int b) {
		a = getParent(a);
		b = getParent(b);
		
		if(a == b) {
			return true;
		}else {
			return false;
		}
		
	}
	
	
	
}
