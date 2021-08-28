

import java.util.ArrayList;
import java.util.Comparator;


public class Solution {
	static class Node {
		int a;
		int b;
		int cost;
		
		public Node(int a, int b, int cost) {
			super();
			this.a = a;
			this.b = b;
			this.cost = cost;
		}
		
		
		
		
	}
	
	
	
	static ArrayList<Node> list;
	static int num[];
    public int minCostConnectPoints(int[][] points) {
    	num = new int[points.length];
    	
    	for(int i = 0 ; i < points.length; i++) {
    		num[i] = i;
    	}
    	
    	list = new ArrayList<Node>();
    	for(int i = 0 ; i < points.length-1;i++) {
    		for(int j = i+1; j < points.length;j++) {
    			list.add( new Node(i,j, Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1]- points[j][1]) ));
    			
    		}
    	}
    	
    	list.sort(new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				// TODO Auto-generated method stub
				return Integer.compare(o1.cost, o2.cost);
			}
		});
    	
    	int sum = 0;
    	for(int i  = 0 ; i < list.size();i++) {
    		Node node = list.get(i);
    		int a = node.a;
    		int b = node.b;
    		int cost =  node.cost;
    		
    		
    		if(!find(a, b)) {
    			union(a, b);
    			sum +=cost;
    		}
    		
    		
    	}
    	
    	
    	
		return sum;
        
    }
    
    public static int getParents(int x) {
    	if( num[x] == x) return x;
    	
    	
    	return getParents(num[x]);
    }
    
    
    public static void union(int a,int b) {
    	a = getParents(a);
    	b = getParents(b);
    	
    	if( a < b) {
    		num[b] = a;
    	}else {
    		num[a] = b;
    	}
    	
    	
    }
    
    public static boolean find(int a,int b) {
    	a = getParents(a);
    	b = getParents(b);
    	
    	if(a == b) {
    		return true;
    	}else {
    		return false;
    	}
    }
    
    
}
