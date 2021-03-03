//미완성
import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static int [][] map;
	static int [] answer;
	static boolean [] visit;
	

	

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		n = Integer.parseInt(bf.readLine());
		map = new int[n+1][n+1];
		answer = new int[n+1];
		visit = new boolean[n+1];
		
	
		for(int i=0;i<n-1;i++) {
			String s[] = bf.readLine().split(" ");
			int a = Integer.parseInt(s[0]);
			int b = Integer.parseInt(s[1]);
			
			map[a][b] = map[b][a] = 1;
		}
		
		
		System.out.println();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				System.out.print(map[i][j]);
			}System.out.println();
		}System.out.println();
		
		
		int a = 1; //시작 지점 값 
		int k = 2;
		for(int i=1;i<=n;i++) {
			visit[a] = true;
			System.out.println("visit["+a+"] = true");
			if(map[a][i] == 1 && !visit[i]) {
				answer[k] = i; visit[i] = true;
				System.out.println("answer[k] = " + answer[k]);
				k++;
			}
			a = answer[++a];
			System.out.println("a = "+ a);
		}
		
		for(int i=2;i<=n;i++) {
			System.out.print(answer[i]+" ");
		}
		
		
		
	}

}


