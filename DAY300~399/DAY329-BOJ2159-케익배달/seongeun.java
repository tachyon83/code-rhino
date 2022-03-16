
public class 케익배달_2159 {

    static int[] dx = {0, 0, 1, 0, -1}; //가운데, 상, 우, 하, 좌
    static int[] dy = {0, -1, 0, 1, 0};
    static long[] dp1;
    static long[] dp2;

    static void getMinDistance(int startX, int startY, int targetX, int targetY) {

        Arrays.fill(dp2, Long.MAX_VALUE);
        for(int i = 0; i < 5; i++) {
            int nextStartX = startX + dx[i];
            int nextStartY = startY + dy[i];
            if( nextStartX < 0 ||  nextStartY < 0 ||  nextStartX >= 100001 ||  nextStartY >= 100001) continue;
            for(int j = 0; j < 5; j++) {
                int nextTargetX = targetX + dx[j];
                int nextTargetY = targetY + dy[j];
                if( nextTargetX < 0 ||  nextTargetY < 0 ||  nextTargetX >= 100001 ||  nextTargetY >= 100001) continue;
                long distance = Math.abs(nextTargetX - nextStartX) + Math.abs(nextTargetY - nextStartY);
                dp2[j] = Math.min(dp2[j], dp1[i] + distance);
            }
        }
        swap();
    }

    static void swap() {
        long[] temp = new long[5];
        for( int i = 0; i < 5; i++) {
            temp[i] = dp1[i];
            dp1[i] = dp2[i];
            dp2[i] = temp[i];
        }
    }

    static void getFirstMinDistance(int startX, int startY, int targetX, int targetY) {

        for( int i = 0; i < 5; i++) {
            int nextX = targetX + dx[i];
            int nextY = targetY + dy[i];
            if(nextX < 0 || nextY < 0 || nextX >= 100001 || nextY >= 100001) continue;
            dp1[i] = Math.abs(nextY - startY) + Math.abs(nextX - startX);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        dp1 = new long[5];
        dp2 = new long[5];
        StringTokenizer st = new StringTokenizer(input.readLine());
        int startX = Integer.parseInt(st.nextToken());
        int startY = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(input.readLine());
        int targetX = Integer.parseInt(st.nextToken());
        int targetY = Integer.parseInt(st.nextToken());
        getFirstMinDistance(startX, startY, targetX, targetY);

        for(int i = 1; i < n; i++) {
            startX = targetX;
            startY = targetY;
            st = new StringTokenizer(input.readLine());
            targetX = Integer.parseInt(st.nextToken());
            targetY = Integer.parseInt(st.nextToken());
            getMinDistance(startX, startY, targetX, targetY);
        }

        long min = Long.MAX_VALUE;
        for(int i = 0; i < 5; i++) {
            min = Math.min(min, dp1[i]);
        }
        System.out.println(min);
    }
}
