import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int[] prices=new int[n+1];
        for (int i = 0; i < n+1; i++) {
            prices[i]=1000000;
        }
        boolean[] visited=new boolean[n+1];

        int[][] graph=new int[n+1][n+1];
        for (int i = 1; i < n+1; i++) {
            int temp=Integer.parseInt(br.readLine());
            graph[0][i]=temp;
            graph[i][0]=temp;
        }
        for (int i = 1; i < n+1; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            for (int j = 1; j < n+1; j++) {
                int temp=Integer.parseInt(st.nextToken());
                graph[i][j]=temp;
                graph[j][i]=temp;
            }
        }
        PriorityQueue<int[]> pq=new PriorityQueue<>((p1, p2) -> p1[1] - p2[1]);
        visited[0]=true;
        for (int i = 0; i < n+1; i++) {
            if(graph[0][i]>0){
                pq.add(new int[]{i,graph[0][i]});
            }
        }

        int answer=0, size=0;
        while (!pq.isEmpty()){
            int[] temp=pq.poll();
            int node=temp[0],price=temp[1];
            if(visited[node]){
                continue;
            }
            visited[node]=true;
            answer+=price;
            if(++size==n){
                break;
            }
            for (int i = 1; i < n+1; i++) {
                if(!visited[i] && graph[node][i]>0 && graph[node][i]<prices[i]){
                    prices[i]=graph[node][i];
                    pq.add(new int[]{i,graph[node][i]});
                }
            }
        }

        System.out.print(answer);
    }

}
