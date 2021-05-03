import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.HashMap;

import java.util.Map;
import java.util.StringTokenizer;


public class Main {
	
	static int name[];
	static double num[];
	static Map<String, String[]> map;
	static Map<String, Integer> blood;
	
	static boolean king[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		String starter = br.readLine();
		
		
		
		map = new HashMap<String, String[]>();
		blood = new HashMap<String, Integer>();
		

		for(int i = 0 ;i < n;i++) {
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			String c = st.nextToken();
			
			map.put(a, new String[] {b,c});
			blood.put(b, 0);
			blood.put(c, 0);
			
		}
		blood.put(starter,1);
		
		
		String ans = "";
		
		double max = 0;
		for(int i = 0 ; i < m;i++) {
			String name = br.readLine();
			double num = dfs(name);
			
			if(max < num) {
				max = num;
				ans = name;
			}
			
		}
		
		System.out.println(ans);
	
		
	}
	
	public static double dfs(String name) {
		
		
		if(map.containsKey(name)) {		
			
			String parents[] = map.get(name);
			
			return (dfs(parents[0])+ dfs(parents[1]))/2;
			
		}else {
			
			if(blood.containsKey(name)) {
				
				return blood.get(name);
			}else {
				return 0;
			}
			
		}
			
		
		
		
		
		
	}
	
	


	
}
