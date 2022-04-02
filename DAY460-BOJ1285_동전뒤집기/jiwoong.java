package submit;

import java.io.*;
import java.util.*;



public class jiwoong{
    public static void main(String []args) throws Exception{
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        char[][] map = new char[n][n];

        for(int i=0;i<n;i++){
            String s = br.readLine();
            for(int j=0;j<n;j++){
                map[i][j] = s.charAt(j);
            }
        }

        int answer = n*n;

        for(int bit=0;bit<(1<<n);bit++){
            int sum = 0;
            for(int i=0;i<n;i++){
                int T = 0;
                for(int j=0;j<n;j++){
                    char cur = map[j][i];
                    if((bit&1<<j)!=0) cur = flip(cur);
                    if(cur=='T') T++;
                }
                sum += Math.min(T,n-T);
            }
            if(sum<answer) answer = sum;
        }
        System.out.println(answer);
    }
    static char flip(char x){
        if(x=='T') return 'H';
        return 'T';
    }
}