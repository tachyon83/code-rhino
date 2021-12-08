public class Main {

    private static int arr[][];
    private static int energe[][];
    private static PriorityQueue<int[]> tree;
    private static Queue<int[]> die;

    private static void spring() {
        //자신의 나이만큼 양분을 먹고, 나이 1 증가 , 양분이 부족하면 죽는다.
        PriorityQueue<int[]> temp = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        while(!tree.isEmpty()){
            int[] tmp = tree.poll();
            int y = tmp[0];
            int x = tmp[1];
            int z = tmp[2];
            if(arr[y][x] - z < 0){
                die.add(new int[]{y,x,z});
            }else{
                arr[y][x] -= z;
                temp.add(new int[]{y,x,z + 1});
            }
        }
        tree.addAll(temp);
    }

    private static void summer() {
        while(!die.isEmpty()){
            int tmp[] = die.poll();
            int y = tmp[0];
            int x = tmp[1];
            int z = tmp[2];
            arr[y][x] += z / 2;
        }
        // 죽은 나무가 나이 / 2 만큼 양분으로
    }

    private static void autumn(int n) {
        Iterator<int []> iter = tree.iterator();
        PriorityQueue<int[]> temp = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        while(iter.hasNext()){
            int[] tmp = iter.next();
            if(tmp[2] % 5 == 0){
                int y = tmp[0];
                int x = tmp[1];
                // 범위 설정 해주기
                if(y  > 1)
                temp.add(new int[]{y - 1,x,1});
                if(y  > 1 && x < n)
                temp.add(new int[]{y - 1,x + 1 ,1});
                if(x < n)
                temp.add(new int[]{y,x + 1,1});
                if(y  < n && x < n)
                temp.add(new int[]{y + 1,x + 1,1});
                if(y  < n)
                temp.add(new int[]{y + 1,x,1});
                if(y  < n && x > 1)
                temp.add(new int[]{y + 1,x - 1,1});
                if(x > 1)
                temp.add(new int[]{y,x - 1,1});
                if(y  > 1 && x > 1)
                temp.add(new int[]{y - 1,x - 1,1});
            }
        }
        tree.addAll(temp);
        // 번식은 나이가 5의 배수일 때만, 인접한 8칸 나무 나이 1 생성
    }

    private static void winter(int n) {
        //양분 추가
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] += energe[i][j];
            }
        }
    }

   public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken()); //맵의 크기
        int m = Integer.parseInt(st.nextToken()); //나무의 개수
        int k = Integer.parseInt(st.nextToken()); //목표 년도
        arr= new int[n + 1][n + 1]; //초기 양분
        energe = new int[n + 1][n + 1]; //겨울에 주는 양분
        tree = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        die = new LinkedList<>();



        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(input.readLine());
            for(int j = 1; j <= n; j++){
                arr[i][j] = 5;
                energe[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 1; i <= m; i++) {
            st = new StringTokenizer(input.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            tree.add(new int[]{y,x,z});
        }

        //년도 마다 돌리기
        for(int i = 1; i <= k; i++){
            //봄
            spring();
            //display(n);
            //여름
            summer();
            //가을
            autumn(n);
            //겨울
            winter(n);
        }
       System.out.println(tree.size());
    }

    private static void display(int n) {
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                sb.append(arr[i][j] + " ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
