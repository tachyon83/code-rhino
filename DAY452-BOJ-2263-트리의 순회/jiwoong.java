import java.io.*;
import java.util.*;



public class jiwoong{
    static int[] inOrder, postOrder, inOrderIdx;
    static StringBuilder sb = new StringBuilder();
    public static void main(String []args) throws Exception{

        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        inOrder = new int[n+1];
        postOrder = new int[n+1];
        inOrderIdx = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            inOrder[i] = Integer.parseInt(st.nextToken());
        }


        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=n;i++){
            postOrder[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=1;i<=n;i++){
            inOrderIdx[inOrder[i]] = i;
        }
        getPreOrder(1, n, 1, n);
        System.out.println(sb.toString());
    }
    public static void getPreOrder(int inO_start, int inO_end, int poO_start, int poO_end) {
        if(inO_start > inO_end || poO_start > poO_end) return;

        int root = postOrder[poO_end];
        sb.append(root + " ");

        int rootIdx = inOrderIdx[root];
        int left = rootIdx - inO_start;

        getPreOrder(inO_start, rootIdx-1, poO_start, poO_start+ left-1);

        getPreOrder(rootIdx+1, inO_end, poO_start + left, poO_end - 1);
    }
}