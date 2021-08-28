import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static HashMap<String, String[]> map = new HashMap<>(); // 자식 - 부모
	static HashMap<String, Integer> blood = new HashMap<>();
	static int[] inDegree;
	static String[] result;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(str.nextToken());
		M = Integer.parseInt(str.nextToken());

		String start = br.readLine();

		for (int i = 0; i < N; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			String a = str.nextToken();
			String b = str.nextToken();
			String c = str.nextToken();
			map.put(a, new String[] { b, c });
			blood.put(b, 0);
			blood.put(c, 0);
		}
		blood.put(start, 1);
		String answer = "";
		double MAX = -1;
		for (int i = 0; i < M; i++) {
			String name = br.readLine();
			double temp = dfs(name);
			if (MAX < temp) {
				answer = name;
				MAX = temp;
			}
		}
		System.out.println(answer);
	}

	private static double dfs(String name) {
		if (map.containsKey(name)) {
			String[] parents = map.get(name);
			return (dfs(parents[0]) + dfs(parents[1])) / 2;
		} else {
			return blood.getOrDefault(name, 0);
		}

	}

}