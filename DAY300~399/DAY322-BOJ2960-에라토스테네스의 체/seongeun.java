
public class 에라토스테네스의체_2960 {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        boolean[] check = new boolean[n + 1];
        check[0] = true;
        check[1] = true;
        int cnt = 0;
        int target = -1;
        for(int i = 2; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                if(!check[j]) {
                    check[j] = true;
                    cnt++;;
                    if(cnt == k) {
                        target = j;
                        break;
                    }
                }
            }
            if(target != -1 ) break;
        }
        System.out.println(target);

    }
}
