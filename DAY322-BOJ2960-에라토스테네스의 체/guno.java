import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;
        st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken()),k=Integer.parseInt(st.nextToken());
        boolean[] num=new boolean[n+1];
        int cnt=0,ans=0;
        boolean isFinished=false;
        for (int i = 2; i < n+1; i++) {
            if(!num[i]){
                for (int j = i; j < n+1; j+=i) {
                    if(num[j])
                        continue;
                    cnt++;
                    if(cnt==k){
                       ans=j;
                       isFinished=true;
                       break;
                    }
                    num[j]=true;
                }
            }
            if(isFinished)
                break;
        }
        sb.append(ans);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
