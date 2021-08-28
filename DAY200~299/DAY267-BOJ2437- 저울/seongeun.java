public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);

        int result = 1;
        for(int i = 0; i < arr.length; i++) {
            if (result < arr[i]) break;
            result += arr[i];
        }

//        for(int i = 1; i < dp.length; i++)
//            if(dp[i] == 0) result = i;
        System.out.println(result);
    }
}
