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
        for (int i = 0; i < n; i++)
            nums[i] = getInt();

        int[] lengths = new int[n];
        int[] prev = new int[n];

        lengths[0] = 1;
        prev[0] = -1;

        for (int i = 1; i < n; i++) {
            int maxLen = 0, idx = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i]>nums[j] && lengths[j] > maxLen) {
                    maxLen = lengths[j];
                    idx = j;
                }
            }
            lengths[i] = maxLen + 1;
            prev[i] = idx;
        }

        int maxLen = -1, idx = -1;
        for (int i = 0; i < n; i++) {
            if (maxLen < lengths[i]) {
                maxLen = lengths[i];
                idx = i;
            }
        }

        List<Integer> list = new ArrayList<>();
        while (idx!=-1){
            list.add(nums[idx]);
            idx = prev[idx];
        }
        sb.append(list.size()).append("\n");

        for (int i = list.size()-1; i >=0 ; i--) {
            sb.append(list.get(i)).append(" ");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
