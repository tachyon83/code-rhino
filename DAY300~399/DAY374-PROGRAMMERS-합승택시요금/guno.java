import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

    static int INF = 100000000;
    static int size;
    static List<Node>[] graph;
    class Node{
        int num;
        int weight;

        public Node(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }
    }
    public int solution(int n, int s, int a, int b, int[][] fares) {
        size = n;
        int answer = Integer.MAX_VALUE;
        int[] d = new int[n+1];
        for (int i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[s] = 0;
        graph = new List[n+1];
        for (int i = 0; i < n+1; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] fare : fares) {
            int x = fare[0], y = fare[1], w = fare[2];
            graph[x].add(new Node(y, w));
            graph[y].add(new Node(x, w));
        }
        int[] ds = daik(s);
        int[] da = daik(a);
        int[] db = daik(b);

        for (int i = 1; i <= n; i++) {
            if (answer > ds[i] + da[i]+db[i]) {
                answer = ds[i] + da[i] + db[i];
            }
        }
        return answer;
    }

    int[] daik(int s) {
        int[] d = new int[size+1];
        for (int i = 0; i < size+1; i++) {
            d[i] = INF;
        }
        PriorityQueue<Node> pq = new PriorityQueue<Node>((o1, o2) -> o1.weight-o2.weight);
        pq.add(new Node(s,0));
        d[s] = 0;
        while (!pq.isEmpty()) {
            Node poll = pq.poll();
            int num = poll.num, weight = poll.weight;
            for (Node node : graph[num]) {
                if (d[node.num] > weight + node.weight) {
                    d[node.num] = weight + node.weight;
                    pq.add(new Node(node.num, d[node.num]));
                }
            }
        }
        return d;
    }

}
