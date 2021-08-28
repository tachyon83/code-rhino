import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Review {

    static int buildingTime[];
    static ArrayList<Integer> connect[];
    static int buildingNum[];
    static int dp[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        for (int i = 0 ; i < t ; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            buildingTime = new int[n+1];
            connect = new ArrayList[n+1];
            buildingNum= new int[n+1];
            dp = new int[n+1];

            st = new StringTokenizer(br.readLine());
            for(int j = 1 ; j <= n ; j++){
                connect[j] = new ArrayList();
                buildingTime[j] = Integer.parseInt(st.nextToken());
            }

            for(int j = 0 ; j < k ; j++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                connect[a].add(b);
                buildingNum[b]++;
            }

            
      
            int w = Integer.parseInt(br.readLine());
            topology(n);
            System.out.println(dp[w]);
        }
    }

    public static void topology(int n){
        Queue<Integer> que = new LinkedList<>();

        for(int i = 1 ; i <=n ;i++){
            dp[i] = buildingTime[i];
            if(buildingNum[i] == 0){
                que.add(i);
            }
        }
        
        for(int i = 1 ; i <=n ;i++){
          
            if(que.isEmpty())return;

            int cur = que.poll();
 
            for(int j = 0; j < connect[cur].size();j++){
                int get = connect[cur].get(j);

                if(dp[get]<dp[cur]+buildingTime[get]){
                    dp[get] = dp[cur]+buildingTime[get];
                }
                buildingNum[get]--;
                
                if(buildingNum[get] == 0) {
                	
                	que.add(get);
                }
                

            }


        }




    }

}
