public class 네트워크연결_1922 {

    static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        parent = new int[n + 1];
        int m = Integer.parseInt(input.readLine());
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        for(int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            pq.add(new int[]{start, end, weight});
        }

        //부모노드 초기화
        for(int i = 1; i <= n; i++) parent[i] = i;


        int cnt = 0;
        int sum = 0;
        while(!pq.isEmpty()) {
            int[] node = pq.poll();
            int start = node[0];
            int end = node[1];
            int weight = node[2];
            int startRootIdx = find(start);
            int endRootIdx = find(end);
            if(startRootIdx == endRootIdx) continue;
            cnt++;
            union(startRootIdx, endRootIdx);
            sum += weight;
            if( cnt == n - 1) break;
        }

        System.out.println(sum);

    }

    private static void union(int startIdx, int endIdx) {
         int startRootIdx = find(startIdx);
         int endRootIdx = find(endIdx);
         if( startRootIdx < endRootIdx) parent[endRootIdx] = startRootIdx;
         else parent[startRootIdx] = endRootIdx;
    }

    private static int find(int idx) {
        if(idx == parent[idx]) return idx;
        return parent[idx] = find(parent[idx]);
    }
}
