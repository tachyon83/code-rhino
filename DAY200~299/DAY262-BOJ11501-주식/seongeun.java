public class 주식_11501 {



    private static long getSum(int[] arr, int n) {
        long sum = 0;
        int index = n - 1;
        for(int j = n - 1; j >= 0; j--){

            if(arr[index] < arr[j]){
                index = j;
            }else{
                sum += arr[index] - arr[j];
            }
        }
        return sum;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int k = Integer.parseInt(input.readLine());
        for(int i = 0; i < k; i++) {
            int n = Integer.parseInt(input.readLine());
            int arr[] = new int[n];

            StringTokenizer st = new StringTokenizer(input.readLine());
            for(int j = 0; j < n; j++)
                arr[j] = Integer.parseInt(st.nextToken());

            sb.append(getSum(arr,n)).append("\n");
        }

        System.out.println(sb);
    }
}
