import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10
 */
public class Main {
    static StringBuilder sb = new StringBuilder();

    static int check(int[] arr, int number) {

        int start = 0;
        int end = arr.length - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(number < arr[mid]) {
                end = mid - 1;
            }else if(number == arr[mid]) {
                return 1;
            }else {
                start = mid + 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);
        int m = Integer.parseInt(input.readLine());
        st = new StringTokenizer(input.readLine());
        for(int i = 0; i < m; i++) {
            int number = Integer.parseInt(st.nextToken());
            sb.append(check(arr,number)).append(" ");
        }
        System.out.println(sb);
    }
}
