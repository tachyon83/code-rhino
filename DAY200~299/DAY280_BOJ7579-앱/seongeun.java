public class 앱_7579 {

    private static int n;
    private static int m;
    private static int[][] arr;
    private static int getMinMemory(int sum) {

        int result = 0;
        int[] dp = new int[sum + 1];
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= arr[i][1]; j--){
                dp[j] = Math.max(dp[j],dp[j - arr[i][1]] + arr[i][0]);
            }
        }


        for(int i = 0 ; i <= sum; i++){
            if(dp[i] >= m){
                result = i;
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][2];

        st = new StringTokenizer(input.readLine());
        for(int i = 0; i < n; i++) arr[i][0] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(input.readLine());
        int sum = 0;
        for(int i = 0; i < n; i++) {
            arr[i][1] = Integer.parseInt(st.nextToken());
            sum += arr[i][1];
        }
        System.out.println(getMinMemory(sum));

    }
}
