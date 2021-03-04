// 11725번 트리의 부모 찾기(silver 2)

// 제출 결과 [메모리: 17340KB 시간: 180ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class BJ_11725 {
    static int n;
    static ArrayList<ArrayList<Integer>> listGraph;
    static int[] parents;
    static boolean[] check;

    public static void dfs(int v){
        check[v] = true;
        for (int vChild : listGraph.get(v)) {
            if(!check[vChild]){
                parents[vChild] = v;
                dfs(vChild);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        listGraph = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < n+1; i++) {
            listGraph.add(new ArrayList<Integer>());
        }

        parents = new int[n+1];
        check = new boolean[n + 1];



        for (int i = 0; i < n-1; i++) {
            String[] inputNode = br.readLine().split(" ");
            int n1 = Integer.parseInt(inputNode[0]);
            int n2 = Integer.parseInt(inputNode[1]);

            listGraph.get(n1).add(n2);
            listGraph.get(n2).add(n1);
        }

        for (int i = 1; i <= n; i++) {
            if(!check[i])
                dfs(i);
        }
        for (int i = 2; i <= n; i++) {
            System.out.println(parents[i]);
        }

    }
}
