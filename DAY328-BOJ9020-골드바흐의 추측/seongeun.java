
public class 골드바흐의추측_9020 {

    static boolean check[];

    static int[] getGoldNumber(int number) {

        int diff = 10001;
        int[] result = new int[2];
        for(int i = 2; i <= number; i++) {
            if(number - i < 0) break;
            //소수라면
            if(!check[i] && !check[number - i]) {
                int newDiff = Math.abs(number - (2 * i));
                if(diff > newDiff ) {
                    diff = newDiff;
                    result[0] = i;
                    result[1] = number - i;
                }
            }
        }
        return result;
    }

    static void getPrimeNumber() {

        //false면 소수, true면 소수가 아님
        for(int i = 2; i <= Math.sqrt(10000) + 1; i++) {
            if(check[i]) continue;
            for(int j = i + i; j <= 10000; j += i) {
                check[j] = true;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(input.readLine());
        check = new boolean[10001];
        getPrimeNumber();
        for(int i = 0; i < n; i++) {
            int number = Integer.parseInt(input.readLine());
            int[] result = getGoldNumber(number);
            sb.append(result[0]).append(" ").append(result[1]).append("\n");
        }
        System.out.println(sb);
    }
}
