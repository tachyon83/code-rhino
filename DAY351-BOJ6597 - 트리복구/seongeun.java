package DataStructure.진행중인문제;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
DBACEGF ABCDEFG
BCAD CBAD
 */
public class 트리복구_6597 {

    static StringBuilder sb = new StringBuilder();

    //PostOrder를 구하기 위해서는 해당 부모 노드, 왼쪽 서브 트리,오른쪽 서브 트리를 알면 된다.
    //부모 노드, 왼쪽 서브 트리, 오른쪽 서브 트리를 알 수 있다면 왼쪽 -> 오른쪽 -> 부모 노드순으로 재귀를 돌린다면 PostOrder를 구할 수 있다.
    //부모노드는 preOrder로 알 수 있다.
    //왼쪽 서브트리는 InOrder의 부모 노드 인덱스 왼쪽  - 오른쪽 서브 트리는 InOrder의 부모 노드 인덱스 오른쪽
    static void getPostOrder(String preOrder, String inOrder) {

        int treeSize = preOrder.length();

        if(treeSize == 0) return;

        //부모 노드 구하기
        char parentNode = preOrder.charAt(0);

        //서브 트리 구분 인덱스
        int idx = inOrder.indexOf(parentNode);

        //왼쪽 서브 트리
        String leftPreOrder = preOrder.substring(1, idx + 1);
        String leftInOrder = inOrder.substring(0, idx);

        //오른쪽 서브 트리
        String rightPreOrder = preOrder.substring(idx + 1);
        String rightInOrder = inOrder.substring(idx + 1);

        //왼쪽 재귀
        getPostOrder(leftPreOrder, leftInOrder);

        //오른쪽 재귀
        getPostOrder(rightPreOrder, rightInOrder);

        //부모 노드 저장
        sb.append(parentNode);

    }

   public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String s = input.readLine();
            if(s == null) break;
            StringTokenizer st = new StringTokenizer(s);
            String preOrder = st.nextToken();
            String inOrder = st.nextToken();
            getPostOrder(preOrder, inOrder);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
