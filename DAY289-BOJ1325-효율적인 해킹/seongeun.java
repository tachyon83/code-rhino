
public class 효율적인해킹_1325 {
    private static ArrayList<Integer>[] list;
    private static int[] result;

    private static void bfs(int idx, int n) {
        boolean visited[] = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(idx);
        visited[idx] = true;

        while(!q.isEmpty()) {
            int index = q.poll();
            for(int val : list[index]) {
                if(visited[val]) continue;
                visited[val] = true;
                result[val]++;
                q.add(val);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++) list[i] = new ArrayList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(input.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            list[start].add(end);
        }
        result = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            bfs(i,n);
        }
        int max = 0;
        for(int i = 1; i <= n; i++){
            max = Math.max(result[i],max);
        }
        for(int i = 1; i <= n; i++){
            if(result[i] == max) sb.append(i).append(" ");
        }
        System.out.println(sb);
    }
}
