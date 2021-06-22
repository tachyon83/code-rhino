
public class 트리의순회_2263 {

    private static int[] inOrder;
    private static int[] postOrder;
    //rootIdx를 기준으로 left의 수와 right 수를 구하기 위한 변수 배열
    private static int[] inOrderRootIdx;
    private static StringBuilder sb;

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        inOrder = new int[n + 1];
        postOrder = new int[n + 1];
        inOrderRootIdx = new int[n + 1];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 1; i <= n; i++) inOrder[i] = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= n; i++) inOrderRootIdx[inOrder[i]] = i;
        st = new StringTokenizer(input.readLine());
        for(int i = 1; i <= n; i++) postOrder[i] = Integer.parseInt(st.nextToken());
        preOrder(1,n,1,n);
        System.out.println(sb);
    }

    private static void preOrder(int inOrderLeft, int inOrderRight, int postOrderLeft, int postOrderRight) {

        if(inOrderLeft > inOrderRight || postOrderLeft > postOrderRight) return;
        //root를 먼저 구하자.
        int root = postOrder[postOrderRight];
        sb.append(root + " ");

        //root의 index를 구하자.
        int rootIdx = inOrder[root];

        //left의 개수를 count
        int leftCount = rootIdx - inOrderLeft;

        //left
        preOrder(inOrderLeft,rootIdx - 1, postOrderLeft, postOrderLeft - 1 + leftCount);

        //right
        preOrder(rootIdx + 1, inOrderRight, postOrderLeft + leftCount, postOrderRight - 1);
    }
}
