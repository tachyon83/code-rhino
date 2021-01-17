import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<String, Integer> map = new HashMap<>();

		int total = 0;
		String tree;
		while (true) {
			tree = br.readLine();
			if (tree==null || ("").equals(tree) || tree.length() == 0) {
				break;
			}
			if (map.containsKey(tree)) {
				map.put(tree, map.get(tree) + 1);
			} else {
				map.put(tree, 1);
			}
			total++;
		}
		Object[] keys = map.keySet().toArray();
		Arrays.sort(keys);

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < keys.length; i++) {
			tree = (String) keys[i];
			float rate = (float)((float)(map.get(tree) * 100) / (float)total);
			sb.append(tree).append(" ").append(String.format("%.4f", rate)).append("\n");
		}

		System.out.println(sb.toString());

	}

}