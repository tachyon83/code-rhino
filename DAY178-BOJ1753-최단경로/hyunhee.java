import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static class Node {
		int end;
		int price;

		public Node(int end, int price) {
			this.end = end;
			this.price = price;
		}

	}

	static int[] distance;
	static List<Node>[] adjList;
	static int V, E;
	static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer str = new StringTokenizer(br.readLine(), " ");
		V = Integer.parseInt(str.nextToken()); // 정점 개수
		E = Integer.parseInt(str.nextToken()); // 간선 개수

		distance = new int[V + 1];
		Arrays.fill(distance, INF);

		adjList = new ArrayList[V + 1];
		for (int i = 1; i <= V; i++) {
			adjList[i] = new ArrayList<>();
		}

		// 이제 그래프 입력받자
		int K = Integer.parseInt(br.readLine()); // 시작 정점
		distance[K] = 0;

		for (int i = 0; i < E; i++) { // 간선 정보 저장
			str = new StringTokenizer(br.readLine(), " ");
			int start = Integer.parseInt(str.nextToken());
			int end = Integer.parseInt(str.nextToken());
			int price = Integer.parseInt(str.nextToken());
			adjList[start].add(new Node(end, price));
		}

		dijkstra(K);

		for (int i = 1; i <= V; i++) {
			bw.write(distance[i] == INF ? "INF" : (distance[i] + ""));
			bw.newLine();
		}

		bw.flush();

	}

	private static void dijkstra(int start) {

		PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				return Integer.compare(o1.price, o2.price);
			}
		});

		pq.add(new Node(start, 0));

		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			for (int i = 0; i < adjList[cur.end].size(); i++) {
				Node next = adjList[cur.end].get(i);

				if (distance[next.end] > cur.price + next.price) { // 지금 온 방법이 이전에 저장한 것보다 가중치가 낮으면
					distance[next.end] = cur.price + next.price;
					pq.add(new Node(next.end, distance[next.end]));
				}
			}

		}

	}

}