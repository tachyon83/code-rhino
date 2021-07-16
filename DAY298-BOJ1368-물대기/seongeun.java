

public class 물대기_1368 {

    private static int find(int node, int[] parent) {
        if(node == parent[node]) return node;
        return find(parent[node], parent);
    }

    private static void union(int startIdx, int endIdx, int[] parent) {

        int startRootIdx = find(startIdx, parent);
        int endRootIdx = find(endIdx, parent);
        if(startRootIdx < endRootIdx) parent[endRootIdx] = startRootIdx;
        else parent[startRootIdx] = endRootIdx;
    }

    private static int getMinWater(int n, int[] weights, int[][] map) {

        int result = 0;

        int[] parent = new int[n + 1];
        for(int i = 0; i <=n; i++) parent[i] = i;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);

        for(int i = 0; i <= n; i++) {
            for( int j = 0; j <= n; j++) {
                if(i == j) continue;
                if(i != 0 && j != 0) {
                    pq.add(new int[]{i, j, map[i][j]});
                    continue;
                }
                pq.add(new int[]{0, j, weights[j]});
            }
        }


        int cnt = 0;

        while(!pq.isEmpty()) {
            int[] node = pq.poll();
            int start = node[0];
            int end = node[1];
            int value = node[2];
            int startRootIdx = find(start, parent);
            int endRootIdx = find(end, parent);

            if( startRootIdx == endRootIdx) continue;
            union(startRootIdx, endRootIdx, parent);
            result += value;
            cnt++;
            if(cnt == n) break;

        }


        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] weights = new int[n + 1];
        for( int i = 1; i <= n; i++) {
            int w = Integer.parseInt(input.readLine());
            weights[i] = w;
        }
        int[][] map = new int[n + 1][n + 1];
        for( int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            for( int j = 1; j <= n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(getMinWater(n,weights,map));

    }
}
