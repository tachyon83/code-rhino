import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BOJ2666 {

    static List<Integer> opens;
    static int[] target;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        opens = new ArrayList<>();
        Arrays.stream(line).forEach(s -> opens.add(Integer.parseInt(s)));
        int test = Integer.parseInt(br.readLine());

        target = new int[test];
        for (int i = 0; i < test; i++) {
            target[i] = Integer.parseInt(br.readLine());
        }
        System.out.println(solve(0, opens.get(0), opens.get(1)));

    }

    private static int solve(int count, int x, int y) {
        if (count == target.length) {
            return 0;
        }
        int t1 = Math.abs(x - target[count]);
        int t2 = Math.abs(y - target[count]);
        return Math.min(t1 + solve(count + 1, y, target[count]), t2 + solve(count + 1, x, target[count]));
    }
}
