

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 하노이탑이동순서_11729 {

    private static StringBuilder sb = new StringBuilder();
    private static int count = 0;
    private static void hanoi(int left, int mid, int right, int cnt) {

        if(cnt == 0) return;
        hanoi(left, right, mid,cnt - 1);
        count++;
        sb.append(left).append(" ").append(right).append("\n");
        hanoi(mid, left, right,cnt - 1);
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        hanoi(1,2,3,n);
        System.out.println(count);
        System.out.println(sb);
    }
}
