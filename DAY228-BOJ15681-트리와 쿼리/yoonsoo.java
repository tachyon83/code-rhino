import java.io.BufferedReader;
import java.io.IOException;

import java.io.InputStreamReader;

import java.util.ArrayList;

import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer> list[];
    static boolean visited[];
    static int cnt = 1;
    static int num[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        // 정점의 수
        int n = Integer.parseInt(st.nextToken());
        //루트의 번호
        int r = Integer.parseInt(st.nextToken());
        //쿼리의 수
        int q = Integer.parseInt(st.nextToken());

        list = new ArrayList[n+1];
        visited = new boolean[n+1];
        num = new int[n+1];


        for(int i = 1 ; i <= n;i++){
            list[i] = new ArrayList<Integer>();

        }

        for(int i = 0 ; i < n-1;i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
            list[b].add(a);

        }



        visited[r] = true;
        dfs(r);

//        System.out.println(Arrays.toString(num));
        for(int i = 0 ; i < q;i++){
            int root = Integer.parseInt(br.readLine());
            System.out.println(num[root]);
        }


    }
    public static int dfs(int start){


        for(int nodeNum : list[start]){
            if(!visited[nodeNum]){
                visited[nodeNum] = true;

                num[start] += dfs(nodeNum);
            }
        }


        return  num[start]+=1 ;

    }


}




