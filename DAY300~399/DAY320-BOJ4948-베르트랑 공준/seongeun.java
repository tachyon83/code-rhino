public class 베르트랑공준_4948 {

    static final int N = 123456;
    static int[] prime = new int[2 * N + 1];
    static boolean[] visited = new boolean[2 * N + 1];
    static int getPrimeFromNto2N(int n) {
        return prime[2 * n] - prime[n];
    }

    static void calculatePrime() {

        int cnt = 0;
        for(int i = 2; i <= Math.sqrt(2 * N) + 1; i++) {
            if( visited[i] ) continue;
            for(int j = i + i; j <= 2 * N; j += i) {
                visited[j] = true;
            }
        }

        for(int i = 2; i <= 2 * N; i++) {
            if(!visited[i]) {
                prime[i] = prime[i - 1] + 1;
            } else {
                prime[i] = prime[i - 1];
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        calculatePrime();
        while(true) {
            int n = Integer.parseInt(input.readLine());
            if( n == 0 ) break;
            sb.append(getPrimeFromNto2N(n)).append("\n");
        }
        System.out.println(sb);
    }
}
