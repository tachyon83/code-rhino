
public class 추월_2002 {
    public static void main( String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Integer> map = new HashMap<>();
        int n = Integer.parseInt(input.readLine());
        for(int i = 1; i <= n; i++) {
            String str = input.readLine();
            map.put(str, i);
        }
        int result = 0;
        int[] arr = new int[n];
        for( int i = 0; i < n; i++) {
            String str = input.readLine();
            arr[i] = map.get(str);
        }

        for(int i = 0; i < n; i++) {
            for( int j = i; j < n; j++) {
                if(arr[i] > arr[j]){
                    result++;
                    break;
                }
            }
        }
        System.out.println(result);
    }
}
