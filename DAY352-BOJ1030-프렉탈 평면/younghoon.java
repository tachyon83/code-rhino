import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1030 {
    static int s;
    static int n;
    static int k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final String[] inputs = br.readLine().split(" ");
        s = Integer.parseInt(inputs[0]);
        n = Integer.parseInt(inputs[1]);
        k = Integer.parseInt(inputs[2]);
        final int r1 = Integer.parseInt(inputs[3]);
        final int r2 = Integer.parseInt(inputs[4]);
        final int c1 = Integer.parseInt(inputs[5]);
        final int c2 = Integer.parseInt(inputs[6]);

        StringBuilder result = new StringBuilder();
        int length = (int) Math.pow(n, s);
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                result.append(determine(length, i, j));
            }
            result.append("\n");
        }
        System.out.println(result);
    }

    private static String determine(int length, int i, int j) {
        if (length == 1) {
            return "0";
        }
        final int sublength = length / n;
        final int start = sublength * (n - k);
        final int end = sublength * (n + k) / 2;

        if (i >= start / 2 && i < end && j >= start / 2 && j < end) {
            return "1";
        }
        return determine(sublength, i % sublength, j % sublength);
    }
}
