public class Main {

    static ArrayList<int[]>[] list;
    static boolean visited[];

    private static void addNode(int start, int end, int weight) {
        list[start].add(new int[]{end, weight});
        list[end].add(new int[]{start, weight});
    }

    static int getDistance(int start, int end) {

        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        visited[start] = true;
        pq.add(new int[]{start, 0});
        while(!pq.isEmpty()) {
            int[] present_node = pq.poll();
            int present = present_node[0];
            int present_weight = present_node[1];
            if(present == end) {
                return present_node[1];
            }
            for(int[] node : list[present]) {
                int next = node[0];
                if(visited[next]) continue;
                int weight = node[1];
                pq.add(new int[]{next, present_weight + weight});
                visited[next] = true;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        list = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) list[i] = new ArrayList<>();
        int m = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= n - 1; i++) {
            st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            addNode(start, end, weight);
        }
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            visited = new boolean[n + 1];
            sb.append(getDistance(start, end)).append("\n");
        }
        System.out.println(sb);
    }
}
