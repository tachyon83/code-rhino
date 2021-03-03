import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static List<Integer>[] tree;
	static int[] parents;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 1번 노드를 시작으로 내려가면서 자식의 부모를 알려주는 방식

		N = Integer.parseInt(br.readLine());
		tree = new ArrayList[N + 1]; // 1번 노드 부터 N번 노드까지
		for (int i = 1; i <= N; i++) {
			tree[i] = new ArrayList<>();
		}

		parents = new int[N + 1]; // 각 노드의 부모노드를 저장할 공간

		for (int n = 0; n < N - 1; n++) {
			StringTokenizer str = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(str.nextToken());
			int b = Integer.parseInt(str.nextToken());
			tree[a].add(b);
			tree[b].add(a);
		}

		parents[1] = 1;
		dfs(1);
		
		for(int i=2;i<=N;i++) {
			bw.write(parents[i]+"");
			bw.newLine();
		}
		
		bw.flush();
		
	}

	private static void dfs(int p) {

		for (int i = 0; i < tree[p].size(); i++) {
			int son = tree[p].get(i);
			if (parents[son] == 0) {
				parents[son] = p;
				dfs(son);
			}
		}
	}

}