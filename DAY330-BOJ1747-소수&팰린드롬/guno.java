import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        boolean[] isPrime = new boolean[2000001];
        Arrays.fill(isPrime,true);
        isPrime[1]=false;
        for (int i = 2; i < 1500; i++) {
            if(isPrime[i]){
                for (int j = i*2; j < 2000001; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        int ans = 0;
        for (int i = n; i < 2000001; i++) {
            if(isPrime[i]){
                String s = String.valueOf(i);
                boolean flag = true;
                for (int j = 0; j < s.length()/2+1; j++) {
                    if(s.charAt(j)!=s.charAt(s.length()-1-j)){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    ans = i;
                    break;
                }
            }
        }

        sb.append(ans);
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

}
