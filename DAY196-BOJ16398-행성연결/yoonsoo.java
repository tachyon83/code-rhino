import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

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
	static ArrayList<Node> info;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		num = new int[n];
		info = new ArrayList<Node>();
		
		
		for(int i = 0 ; i < n; i++) {
			num[i] = i;
		}

		long sum = 0;
		for(int i = 0 ; i < n; i++) {
			String tmp[] = br.readLine().split(" ");
		
			for(int j =i+1 ; j < n ;j++) {
				int d = Integer.parseInt(tmp[j]);
				info.add(new Node(i, j, d));
			}
		}
	
		Collections.sort(info,new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				if(o1.dis>o2.dis) {
					return 1;
				}else if(o2.dis>o1.dis){
					return -1;
				}else {
					return 0;
				}
			}
		});
		for(int i = 0; i < info.size();i++) {
			int a = info.get(i).a;
			int b = info.get(i).b;
			
			if(!find(a, b)) {
				union(a, b);
				sum+=info.get(i).dis;
			}
		}
		
		System.out.println(sum);
			
		
		
		
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
			num[a] = b;
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
