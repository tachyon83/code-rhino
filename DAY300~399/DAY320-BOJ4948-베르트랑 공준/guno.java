import java.io.*;
import java.util.*;

public class Main {

    static int MAX =123456*2;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        int size=(int) Math.ceil(Math.sqrt(MAX));
        boolean[] isPrime=new boolean[MAX +1];
        Arrays.fill(isPrime,true);
        isPrime[1]=false;
        for (int i = 2; i <= size; i++) {
            if(isPrime[i])
                for (int j = i*2; j <= MAX; j+=i)
                    isPrime[j]=false;
        }

        while (true){
            int n=Integer.parseInt(br.readLine());
            if(n==0)
                break;
            int cnt=0;
            for (int i = n+1; i <= Math.min(2*n, MAX) ; i++) {
                if(isPrime[i])
                    cnt++;
            }
            sb.append(cnt).append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
