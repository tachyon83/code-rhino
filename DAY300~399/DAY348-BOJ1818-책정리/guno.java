import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }


    public static void main(String[] args) throws Exception {

        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = getInt();
        }
        List<Integer> lis = new ArrayList<>();

        lis.add(nums[0]);
        for (int i = 1; i < n; i++) {
            int l = 0, r = lis.size() - 1;
            int num = nums[i];
            while (l!=r){
                int mid = (l+r)/2;
                if (lis.get(mid) > num)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l == lis.size() - 1 && num > lis.get(l)) {
                lis.add(num);
            } else {
                lis.set(l, num);
            }
        }
        sb.append(n-lis.size());

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
