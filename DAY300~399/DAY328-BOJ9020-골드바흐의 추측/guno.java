import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        boolean[] isPrime = new boolean[10001];
        Arrays.fill(isPrime,true);
        for (int i = 2; i < 10001; i++) {
            if(isPrime[i]){
                for (int j = i*2; j < 10001; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        int n=Integer.parseInt(br.readLine());
        while (n-->0){
            int num = Integer.parseInt(br.readLine());
            int temp = num/2;
            while (temp>0){
                if(isPrime[temp] && isPrime[num-temp]){
                    sb.append(temp).append(" ").append(num-temp).append("\n");
                    break;
                }
                temp--;
            }
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
