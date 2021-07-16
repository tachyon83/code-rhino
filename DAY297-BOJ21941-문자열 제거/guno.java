import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class boj_21941 {
    public static void main(String[] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        int m=Integer.parseInt(br.readLine());

        ArrayList<Integer> scores=new ArrayList<>();
        ArrayList<String> words=new ArrayList<>();
        int[] dp=new int[s.length()];
        for(int i=0;i<dp.length;i++) {
            dp[i]=i+1;
        }
        for(int i=0;i<m;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            int x = Integer.parseInt(st.nextToken());

            if(a.length()<x){
                words.add(a);
                scores.add(x);
            }
        }


        for(int i=0;i<s.length();i++) {
            for (int j = 0; j < words.size(); j++) {
                String word=words.get(j);
                int k;
                for(k=0;k<word.length();k++){
                    if(i-k<0 || s.charAt(i-k)!=word.charAt(word.length()-k-1)){
                        break;
                    }
                }

                if(k==word.length()){
                    int prev=i-k<0?0:dp[i-k];
                    if(dp[i]<prev+scores.get(j)){
                        dp[i]=prev+scores.get((j));
                    }
                }
            }
            if(i!=0)
                dp[i]=dp[i]>dp[i-1]+1?dp[i]:dp[i-1]+1;
        }

        bw.write(dp[dp.length-1]+ "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
