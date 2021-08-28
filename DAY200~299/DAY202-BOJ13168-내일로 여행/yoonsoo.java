import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	
	static int n;
	static double num[][];
	static double tomorrow[][];
	static String city[];
	static String tripcity[];
	static HashMap<String, Integer> map;
	static int INF = 100000001;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		map = new HashMap<String, Integer>();
		n = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		
		
		
		num = new double[n][n];
		tomorrow = new double[n][n];
		
		city = br.readLine().split(" ");
		for(int i = 0 ; i < n;i++) {
			map.put(city[i], i);
			
		}
		
		for(int i =0 ; i < n; i++) {
			for(int j =0; j < n ;j++) {
				if(i == j) continue;
				num[i][j] = INF;
				tomorrow[i][j] = INF;
			}
		}
		
		int m =  Integer.parseInt(br.readLine());
		
		tripcity = br.readLine().split(" ");
		
		int k = Integer.parseInt(br.readLine());

		for(int i = 0 ; i < k;i++) {
			st = new StringTokenizer(br.readLine());
			String type = st.nextToken();
			String a = st.nextToken();
			String b = st.nextToken();
			double cost = Integer.parseInt(st.nextToken());
			
			
			if(type.equals("Mugunghwa")|| type.equals("ITX-Saemaeul")||type.equals("ITX-Cheongchun")) {
				
				num[map.get(a)][map.get(b)] = 0;
				num[map.get(b)][map.get(a)] = 0;

			}else if (type.equals("S-Train") ||type.equals("V-Train")) {
				
				num[map.get(a)][map.get(b)] = Math.min(num[map.get(a)][map.get(b)], cost/2);
				num[map.get(b)][map.get(a)] = Math.min(num[map.get(b)][map.get(a)], cost/2);

			}else {

				num[map.get(a)][map.get(b)] = Math.min(num[map.get(a)][map.get(b)], cost);
				num[map.get(b)][map.get(a)] = Math.min(num[map.get(b)][map.get(a)], cost);
				
			}
			
			
			tomorrow[map.get(a)][map.get(b)] = Math.min(tomorrow[map.get(a)][map.get(b)], cost);
			tomorrow[map.get(b)][map.get(a)] = Math.min(tomorrow[map.get(b)][map.get(a)], cost);
			
			
		
		}
		
		floyd();
		
		double sum = 0;
		double tomorrowsum = 0;
		String before = tripcity[0];
		for(int i = 1 ; i < m;i++) {
//			System.out.println("경로"+before+"도착"+tripcity[i]+"돈"+num[map.get(before)][map.get(tripcity[i])]);
			sum+=num[map.get(before)][map.get(tripcity[i])];
			tomorrowsum+=tomorrow[map.get(before)][map.get(tripcity[i])];
			before = tripcity[i];
			
		}
//		System.out.println(sum+r);
//		System.out.println(tomorrowsum);
		System.out.println(sum+r < tomorrowsum ? "Yes" : "No");
		
	}
	
	public static void floyd() {
		
		
		for(int i = 0 ; i < n ;i++) {
			for(int j = 0 ; j < n;j++) {
				for(int k = 0; k < n;k++) {
					if(num[i][j] != INF && num[i][k] != INF) {
						num[j][k] = Math.min(num[j][k],  num[j][i] + num[i][k]);
					}
					
					if(tomorrow[i][j] != INF && tomorrow[i][k] != INF) {
						tomorrow[j][k] = Math.min(tomorrow[j][k],  tomorrow[j][i] + tomorrow[i][k]);
					}
					
				}
			}
		}
		
	}
	
	
}
