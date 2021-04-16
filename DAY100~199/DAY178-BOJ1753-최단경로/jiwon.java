//
package bata;

import java.io.*;
import java.util.*;


public class Main {
	static int map[][] ;
	static int dijk[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sb = new StringBuffer();
		
		String s[] = bf.readLine().split(" ");
		int v = Integer.parseInt(s[0]);
		int e = Integer.parseInt(s[1]);
		
		map = new int [v+1][v+1];
		dijk = new int [v+1];
		
		for(int i=0;i<=v;i++) {
			for(int j=0;j<=v;j++) {
				map[i][j] = 100001;
			}
		}
		int x = Integer.parseInt(bf.readLine());
		
		for(int i=0;i<e;i++) {
			String s2[] = bf.readLine().split(" ");
			int a = Integer.parseInt(s2[0]);
			int b = Integer.parseInt(s2[1]);
			int c = Integer.parseInt(s2[2]);
			map[a][b] = c;
		}
	
		for(int i=1;i<=v;i++) {
			dijk[i] = map[x][i];
		}
		dijk[x] = 0;
		
		
		for(int i=1;i<=v;i++) {
			for(int k=1;k<=v;k++) {
				if(i==k) {continue;}
				if(map[x][i] > map[x][k]+ map[k][i]) {
					map[x][i] = map[x][k]+map[k][i];
					//System.out.println("k is "+k+", map[x][i] = "+map[x][i]);
					dijk[i] = map[x][i];
				}
			}
			
		}
		
		for(int i=1;i<=v;i++) {
			if(dijk[i] > 100000) {
				sb.append("INF\n");
			}else {
				sb.append(dijk[i]+"\n");
			}
			
		}
		System.out.println(sb);
		
		
		

	}
	
	

}
