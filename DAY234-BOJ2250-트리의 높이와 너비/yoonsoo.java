import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static class Node{
        int left;
        int right;

        public Node(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    static ArrayList<Node> list[];
    static int node[];
    static int min[] = new int[100001];
    static int max[] = new int[100001];
    static int nodeIdx;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        list = new ArrayList[n+1];
        node = new int[n+1];
        for(int i = 1 ; i <=n;i++){
            list[i] = new ArrayList<Node>();
        }

        for(int i = 0 ; i < n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int nodeNum =Integer.parseInt(st.nextToken());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());



            if(left != -1 ){
                node[left]++;
            }
            if(right != -1) {
                node[right]++;
            }

            list[nodeNum].add(new Node(left,right));

        }


        int root = 0;
        for(int i = 1 ; i <= n;i++){
            if(node[i] == 0 ){
                root = i;
                break;
            }
        }


        nodeIdx = 1;
        Arrays.fill(min,Integer.MAX_VALUE);

        dfs(root,1);

        int depth = 1;
        int result = max[1]-min[1]+1;

        for(int i = 2 ; i <= n; i++){

            int temp = max[i]-min[i]+1;
            if(temp >  result){
                result = temp;
                depth = i;
            }

        }


        System.out.println(depth+" "+result);

    }


    //중위순회
    public static void dfs(int nodeNum,int depth){

        Node cur =  list[nodeNum].get(0);

        if(cur.left >0){
            dfs(cur.left,depth+1);
        }
        min[depth] = Math.min(min[depth],nodeIdx);
        max[depth] = Math.max(max[depth],nodeIdx++);

        if(cur.right >0){
            dfs(cur.right,depth+1);
        }


    }



}
