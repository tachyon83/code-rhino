
public class 기상캐스터_10709 {

    static char[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];

        for(int i = 0; i < n; i++) {
            String str = input.readLine();
            for(int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
            }
        }

        for(int i = 0; i < n; i++) {
            int value = -1;
            for(int j = 0; j < m; j++) {
                if( arr[i][j] == '.') {
                    if(value == -1) sb.append(value).append(" ");
                    else sb.append(value++).append(" ");
                }
                if( arr[i][j] == 'c') {
                    value = 0;
                    sb.append(value++).append(" ");
                }
            }
            sb.append("\n");
        }

        System.out.println(sb);

    }
}
