// 1504번 특정한 최단 경로(gold 4)

// 제출 결과 [메모리: 83480KB 시간: 936ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class BJ_1504 {

    static class Node implements Comparable<Node> {

        private int to;
        private int weight;

        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }

    static int n, m;
    static int[] dist;
    static boolean[] visit;
    static ArrayList<ArrayList<Node>> list = new ArrayList<>();
    static final int INF = 200000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nodeCount = br.readLine().split(" ");
        int start, end, weight;

        n = Integer.parseInt(nodeCount[0]);
        m = Integer.parseInt(nodeCount[1]);

        dist = new int[n + 1];
        visit = new boolean[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        for (int i = 0; i <= n; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            String[] nodeInput = br.readLine().split(" ");
            start = Integer.parseInt(nodeInput[0]);
            end = Integer.parseInt(nodeInput[1]);
            weight = Integer.parseInt(nodeInput[2]);

            list.get(start).add(new Node(end, weight));
            list.get(end).add(new Node(start, weight));
        }

        String[] necessaryNode = br.readLine().split(" ");
        int v1 = Integer.parseInt(necessaryNode[0]);
        int v2 = Integer.parseInt(necessaryNode[1]);

        int v1ToV2 = 0;
        v1ToV2 += dijkstra(1, v1);
        v1ToV2 += dijkstra(v1, v2);
        v1ToV2 += dijkstra(v2, n);

        int v2Tov1 = 0;
        v2Tov1 += dijkstra(1, v2);
        v2Tov1 += dijkstra(v2, v1);
        v2Tov1 += dijkstra(v1, n);

        int result = (v1ToV2 >= INF && v2Tov1 >= INF) ? -1 : Math.min(v1ToV2, v2Tov1);
        System.out.println(result);
    }

    private static int dijkstra(int start, int end) {
        Arrays.fill(dist, INF);
        Arrays.fill(visit, false);

        dist[start] = 0;
        Node node = new Node(start, 0);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(node);

        while(!pq.isEmpty()) {
            Node current = pq.poll();
            int to = current.to;

            if(visit[to]) continue;

            visit[to] = true;
            ArrayList<Node> nextNodes = list.get(to);

            for (Node nextNode : nextNodes) {
                if(!visit[nextNode.to] && dist[nextNode.to] > dist[to] + nextNode.weight) {
                    dist[nextNode.to] = dist[to] + nextNode.weight;
                    pq.add(new Node(nextNode.to, dist[nextNode.to]));
                }
            }
        }

        return dist[end];
    }
}
