// 예제는 통과가 되고 특정 예제에서 틀렸다 나오는데 기대값이 5일 때 제 코드로는 4가 나온다고 했지만, 로컬의 제 IDE를 통해 돌리면 5가 나옵니다.
// 몇 번을 시도해도 같은 결과가 나와 우선은 코드를 올립니다.
// 추가로 dp로 풀 수 있는 것 같은데 학습 분야가 dijkstra 이므로 이를 이용해 풀었습니다.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class LC_787 {
    
    static class Node implements Comparable<Node>{
        int to;
        int weight;
        
        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    
        @Override public int compareTo (Node o) {
            return this.weight - o.weight;
        }
    }
    
    static int n;
    static int[] dist;
    static boolean[] visit;
    static ArrayList<ArrayList<Node>> list = new ArrayList<>();
    
    public static void main (String[] args) {
        n = 5;
        int[][] edges = {{1,2,10}, {2,0,7}, {1,3,8},{4,0,10},{3,4,2},{4,2,10},{0,3,3},{3,1,6},{2,4,5}};
        int src = 0;
        int dst = 4;
        int k = 1;
    
        Solution(n, edges, src, dst, k);
        
    }
    
    private static void Solution (int n, int[][] edges, int src, int dst, int k) {
        dist = new int[n+1];
        visit = new boolean[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        int start, end, weight;
    
        for (int i = 0; i <= n; i++) {
            list.add(new ArrayList<>());
        }
    
        for (int i = 0; i < edges.length; i++) {
            start = edges[i][0];
            end = edges[i][1];
            weight = edges[i][2];
            
            list.get(start).add(new Node(end, weight));
        }
    
        if (dijkstra(src, dst, k) == Integer.MAX_VALUE) {
            System.out.println(-1);
        }else{
            System.out.println(dijkstra(src, dst, k));
        }
    }
    
    private static int dijkstra (int src, int dst, int k) {
        dist[src] = 0;
        int count = -1;
        Node node = new Node(src, 0);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(node);
        
        while(!pq.isEmpty()){
            Node current = pq.poll();
            int to = current.to;
            System.out.println("current Node to:"+to +" weight:"+current.weight);
            
            if(visit[to]) continue;
            
            if(count == k){
                return dist[dst];
            }
            
            visit[to] = true;
            count++;
            ArrayList<Node> nextNodes = list.get(to);
    
            for (Node nextNode : nextNodes) {
                if (!visit[nextNode.to] && dist[nextNode.to] > dist[to] + nextNode.weight) {
                    dist[nextNode.to] = dist[to] + nextNode.weight;
                    pq.add(new Node(nextNode.to, dist[nextNode.to]));
                }
            }
        }
        
        return dist[dst];
    }
    
}
