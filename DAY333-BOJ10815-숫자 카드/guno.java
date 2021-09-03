import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(nums);
        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < m; i++) {
            int num = Integer.parseInt(st.nextToken());
            int l=0,r=n-1;
            while (l<r){
                int mid = (l+r)/2;
                if(nums[mid]<num)
                    l = mid + 1;
                else
                    r = mid;
            }
            if(nums[l]==num)
                sb.append(1).append(" ");
            else
                sb.append(0).append(" ");
        }


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
