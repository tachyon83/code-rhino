public class Main {

    private static int getValue(int n, int[] arr) {

        int result = 0;
        int[][] attacks = {{9, 3, 1},{9, 1, 3},{3, 9, 1},{3, 1, 9},{1, 3, 9},{1, 9, 3}};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{arr[0],arr[1],arr[2],0});
        boolean visited[][][] = new boolean[61][61][61];


        while(!q.isEmpty()){
            int[] scv = q.poll();
            int idx1 = scv[0];
            int idx2 = scv[1];
            int idx3 = scv[2];

            //System.out.println(idx1 + " " + idx2 + " " + idx3);
            if(idx1 <= 0 && idx2 <= 0 && idx3 <= 0){
                result = scv[3];
                break;
            }

            for(int i = 0; i < 6; i++){
                int[] attack = attacks[i];
                int next_idx1 = Math.max(idx1 - attack[0], 0);
                int next_idx2 = Math.max(idx2 - attack[1], 0);
                int next_idx3 = Math.max(idx3 - attack[2], 0);
                if(visited[next_idx1][next_idx2][next_idx3]) continue;
                visited[next_idx1][next_idx2][next_idx3] = true;
                q.add(new int[]{next_idx1,next_idx2,next_idx3,scv[3] + 1});
            }
        }

        return result;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[3];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        System.out.println(getValue(3,arr));
    }
}
