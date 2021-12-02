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
    static void getSt() throws IOException {st = new StringTokenizer(br.readLine());}

    public static void main(String[] args) throws Exception {
        getSt();
        int n = getInt();
        long now = 0;
        long min = Long.MAX_VALUE;
        long ans = 0;
        boolean possible = true;
        for (int i = 0; i < n; i++) {
            getSt();
            long change = Long.parseLong(st.nextToken()), next = Long.parseLong(st.nextToken());

            if (now + change < 0) {// 충전
                change = -change;
                if (ans == 0) {
                    ans = change + next - now;
                }else{
                    ans = gcd(ans, change + next - now);
                }

                if(next!=0)
                    min = Math.min(min, next);
                if (min != Long.MAX_VALUE && ans <= min) {
                    possible = false;
                    break;
                }
                
            } else {
                if (now + change != next) {// 로그 유효성 검사
                    possible = false;
                    break;
                }
            }
            now = next;
        }

        if (!possible) {
            ans = -1;
        } else if (ans == 0) {// 충전 없었을때
            ans = 1;
        }

        sb.append(ans);
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

}
