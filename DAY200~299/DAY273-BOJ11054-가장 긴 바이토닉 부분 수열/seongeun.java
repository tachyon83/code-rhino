public class 가장바이토부분수열_11054 {

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        StringTokenizer st = new StringTokenizer(input.readLine());
        int[] arr = new int[n];
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        Arrays.fill(dp1,1);
        Arrays.fill(dp2,1);
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j] && dp1[i] <= dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = n - 1; j >= i; j--){
                if(arr[i] > arr[j] && dp2[i] <= dp2[j] + 1)
                    dp2[i] = dp2[j] + 1;
            }
        }

        int max = -1;
        for(int i = 0; i < n; i++){
            max = Math.max(max, dp1[i] + dp2[i]);
        }
        System.out.println(max - 1);

    }
}
