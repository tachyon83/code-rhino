
public class Main {

    static long n;
    static int k;

    static long getDistance(long start, long end) {

        HashMap<Long, Integer> parents = new HashMap<>();
        parents.put(start, 0);
        int cnt = 1;
        while(start != 1) {
            start = (start - 2) / k + 1;
            parents.put(start, cnt);
            cnt++;
        }

        long parent = 0;
        cnt = 0;
        while(true) {
            if(parents.get(end) != null) {
                parent = parents.get(end) + cnt;
                break;
            }
            if(end == 1) break;
            end = (end - 2) / k + 1;
            cnt++;
        }

        return parent;
    }


    public static void main( String[] args ) throws Exception {

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Long.parseLong(st.nextToken()); //노드의 개수
        k = Integer.parseInt(st.nextToken()); //한 노드당 자식의 수
        int testCase = Integer.parseInt(st.nextToken()); // 총 몇개의 TestCase가 있는지

        for(int i = 0; i < testCase; i++) {
            st = new StringTokenizer(input.readLine());
            long start = Long.parseLong(st.nextToken());
            long end = Long.parseLong(st.nextToken());
            if(k == 1) sb.append(Math.abs(start - end)).append("\n");
            else sb.append(getDistance(start, end)).append("\n");
        }

        System.out.println(sb);
    }
}
