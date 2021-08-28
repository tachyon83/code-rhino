import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static int[] dp = new int[1000001];
	static int[] number = {3, 5, 8};
	
	public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        
        BFS();
        
        for(int i = 0; i < n; i++){
            int num = Integer.parseInt(br.readLine());
            if(dp[num] == 0) {
            	sb.append("-1");
            	continue;
            }
        }
        System.out.println(sb);
    }
	
    static void BFS() {

        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        dp[0] = -1;
        while(!q.isEmpty()){
            int n = q.poll();
            for(int i = 0; i < 3; i++){
                if(dp[n] == 0) continue;
                if(dp[n + number[i]] == 0) {
                    dp[n + number[i]] = number[i];
                    q.add(n + number[i]);
                }
            }
        }
    }


    
}
