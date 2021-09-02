import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int n;
    private static boolean[] distinct = new boolean[1004001];
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(reader.readLine());
        checkPrime();//소수판별
        int result = 0;

        for (int i=n; i<=1004000; i++) {
            if (i < 10 && distinct[i]) {
                result = i;
                break;
            } else {
                if (checkPelin(Integer.toString(i)) && distinct[i]) {
                    result = i;
                    break;
                }
            }

        }

        System.out.println(result);

    }

    private static boolean checkPelin(String num) {

        int start = 0;
        int end = num.length()-1;

        while (start <= end) {

            if (num.charAt(start) != num.charAt(end)) {
                return false;
            }

            start++;
            end--;

        }

        return true;

    }

    private static void checkPrime() {
        for (int i=2; i<=1004000; i++) {
            distinct[i] = true;
        }

        int num = (int)Math.sqrt(1004000);

        for (int i=2; i<=num; i++) {
            if (distinct[i]) {
                for (int j=i; i*j<=1004000; j++) {
                    distinct[i*j] = false;
                }
            }
        }

    }
}
