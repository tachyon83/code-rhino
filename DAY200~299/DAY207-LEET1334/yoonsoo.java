import java.util.*;
class Solution {
        static int arr[][];
	    static int INF  = 1000000000;
	    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
	    	arr = new int[n][n];
	    	
	    	for(int i = 0 ; i< n ;i++) {
	    		for(int j = 0 ; j < n;j++) {
                    if(i == j ){
                        arr[i][j] = 0 ;
                    }else{
                        arr[i][j] = INF;
                    }
	    			
	    		}
	    	}
	    	
	    	
	    	for(int i = 0 ; i < edges.length;i++) {
	    		int a  = edges[i][0];
	    		int b  = edges[i][1];
	    		int c = edges[i][2];
	    		
	    		arr[a][b] =	 Math.min(arr[a][b],c);
	    		arr[b][a] =	 Math.min(arr[b][a],c);
	    		
	    	}
	    	floyd(n);
            
	    	int min = Integer.MAX_VALUE;
            int idx = 0;
	    	for(int i = 0 ; i< n ;i++) {
	    		int cnt = 0 ;
	    		for(int j = 0 ; j < n;j++) {
                    if(i==j) continue;
                    if(arr[i][j] <= distanceThreshold  ){
                       cnt++;
                    
                    } 
	    			
	    		}
	    		if( min >=cnt) {
	    			idx  = i ;
	    			min = cnt;
	    		}
	    	}
	    	
	    	
			return idx;
	        
	    }
        
    public static void floyd(int n) {
		for(int i = 0 ; i < n ;i++) {
			for(int j = 0 ; j < n; j++) {
				for(int k =0 ; k < n ;k++) {
					if(arr[j][i] == INF || arr[i][k] == INF) {
						continue;
					}
					arr[j][k] = Math.min(arr[j][k],  arr[j][i] + arr[i][k]);
					
				}
			}
		}
	}
	}
