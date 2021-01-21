import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * 포켓몬의 개수 N, 문제의 개수 M. 
 * N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수
 * 
 */

public class Main {
	
//	static List<String> pocketmon = new ArrayList<>();
	static Map<Integer, String> name = new HashMap<>();
	static Map<String, Integer> number = new HashMap<>();
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine()," ");
		int N = Integer.parseInt(str.nextToken());
		int M = Integer.parseInt(str.nextToken());
//		while(N-->0) {
		for(int i=1;i<=N;i++) {
			String pocketmon = br.readLine();
			name.put(i, pocketmon);
			number.put(pocketmon, i);
		}
		while(M-->0) {
			String input = br.readLine();
			try {
				int idx = Integer.parseInt(input);
				sb.append(name.get(idx)).append("\n");
			} catch(NumberFormatException e) {
				sb.append(number.get(input)).append("\n");
			}
		}
		
		System.out.println(sb.toString());
	}

}