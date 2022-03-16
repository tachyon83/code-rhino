public class 트리_10838 {

    static int[] parents;
    static int[] colors;
    static int[] check;

    //a번 노드와 b번 노드의 최단 거리를 찾고 모든 weight를 c로 교체
    private static int findCommonNode(int a, int b, int c) {

        //단, b번 노드는 a번 노드를 루트로 하는 부트리(subtree)에 속하지 않는다.
        //즉, b가 항상 부모노드 이다.
        if( a == b ) return b;

        int cnt = 0;

        while(cnt <= 1001) {

            //a가 0보다 크다면 a는 c로
            if( a > 0) {
                if( check[a] == c) return a;
                check[a] = c;
            }

            if( b > 0) {
                if( check[b] == c) return b;
                check[b] = c;
            }

            if( a > 0) a = parents[a];
            if( b > 0) b = parents[b];
            cnt++;
        }


        return 0;

    }

    private static void paint(int a, int b, int c, int d) {
        //공통 노드를 찾아가면서 weight를 c로 교체

        //공통 노드를 찾고
        int commonNode = findCommonNode(a, b, d);

        //a부터 공통 노드까지 c로 교체
        while(commonNode != a) {
            colors[a] = c;
            a = parents[a];
        }

        //b부터 공통 노드까지 c로 교체
        while(commonNode != b) {
            colors[b] = c;
            b = parents[b];
        }

    }

    //move(a,b) a번 노드의 부모노드를 b번 노드로 바꾼다.

    private static void move(int a, int b) {
        parents[a] = b;
    }

    private static void initNode(int n) {
        for(int i = 1; i <= n; i++) {
            parents[i] = 0;
            colors[i] = 0;
        }
    }

    private static int count(int a, int b, int c) {
        Set<Integer> set = new HashSet<>();

        int commonNode = findCommonNode(a, b, c);

        while(commonNode != a) {
            set.add(colors[a]);
            a = parents[a];
        }

        while(commonNode != b) {
            set.add(colors[b]);
            b = parents[b];
        }

        return set.size();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        parents = new int[100001];
        colors = new int[100001];
        check = new int[100001];
        Arrays.fill(colors, -1);
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        initNode(n);
        int k = Integer.parseInt(st.nextToken());
        for(int i = 0; i < k; i++) {
            st = new StringTokenizer(input.readLine());
            int r = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            //paint(a, b, c) a번 노드와 b번 노드를 잇는 최단 경로를 찾고 그 경로를 c로 바꾼다.
            if( r == 1) {
                int c = Integer.parseInt(st.nextToken());
                paint(a, b, c, i + 1);
            }
            //move(a,b) a번 노드의 부모노드를 b번 노드로 바꾼다.
            if( r == 2) {
                move(a, b);
            }
            //count(a, b) a와 b사이의 서로 다른 color의 수
            if( r == 3) {
                sb.append(count(a,b, i + 1)).append("\n");
            }
        }
        System.out.println(sb);
    }
}
