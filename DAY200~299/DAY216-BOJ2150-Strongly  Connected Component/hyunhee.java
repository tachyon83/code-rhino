import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static ArrayList<Integer>[] graph;
	static boolean[] finished;
	static int id;
	static int[] d;
	static ArrayList<ArrayList<Integer>> SCC = new ArrayList<>();

	static int V, E;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken()) + 1;
		E = Integer.parseInt(str.nextToken());
		finished = new boolean[V];
		graph = new ArrayList[V];
		d = new int[V];
		for (int i = 1; i < V; i++) {
			graph[i] = new ArrayList<>();
		}

		int a, b;

		for (int i = 0; i < E; i++) {
			str = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(str.nextToken());
			b = Integer.parseInt(str.nextToken());
			graph[a].add(b);
		}

		for (int i = 1; i < V; i++) {
			if (d[i] == 0) {
				dfs(i);
			}
		}

		StringBuilder sb = new StringBuilder();
		sb.append(SCC.size()).append("\n");
		for (int i = 0; i < SCC.size(); i++) {
			ArrayList<Integer> al = SCC.get(i);
			Collections.sort(al);
		}
		Collections.sort(SCC, new Comparator<ArrayList<Integer>>() {

			@Override
			public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
				return Integer.compare(o1.get(0), o2.get(0));
			}
		});

		for (ArrayList<Integer> al : SCC) {
			for (Integer z : al) {
				sb.append(z + " ");
			}
			sb.append("-1\n");
		}

		System.out.println(sb.toString());
	}

	static Stack<Integer> stack = new Stack<>();

	private static int dfs(int x) {
		d[x] = ++id;

		stack.push(x);

		int parent = d[x];
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x].get(i);
			if (d[y] == 0) {
				parent = Math.min(parent, dfs(y));
			} else if (!finished[y]) {
				parent = Math.min(parent, d[y]);
			}
		}

		if (parent == d[x]) {
			ArrayList<Integer> scc = new ArrayList<>();
			while (true) {
				int t = stack.pop();
				scc.add(t);
				finished[t] = true;
				if (t == x) {
					break;
				}
			}
			SCC.add(scc);
		}

		return parent;
	}

}