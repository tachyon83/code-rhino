

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


//백준 14675 단절점과 단절선
public class Main {
    static ArrayList<Integer> list[];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n+1];

        for(int i = 1 ; i <= n ; i ++){
            list[i] = new ArrayList<>();
        }

        for(int i = 0 ; i < n-1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            list[a].add(b);
            list[b].add(a);
        }

        int m = Integer.parseInt(br.readLine());

        for(int i = 0 ; i < m;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if( a == 1){
                if(list[b].size()>=2){
                    System.out.println("yes");
                }else{
                    System.out.println("no");
                }

            }else{
                System.out.println("yes");
            }

        }





    }
}
