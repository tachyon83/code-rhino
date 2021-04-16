// 부분수열의 합(silver 2)

// 제출 결과[메모리: 14360KB 시간: 144ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_1182 {

    static int[] sequence;
    static int n, s;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        s = Integer.parseInt(input[1]);

        sequence = new int[n];

        String[] sequenceInput = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            sequence[i] = Integer.parseInt(sequenceInput[i]);
        }

        for (int i = 0; i < n; i++) {
            dfs(i, sequence[i]);
        }

        System.out.println(count);
    }

    private static void dfs(int depth, int sum) {

        if (depth == n - 1 && sum == s) {
            count++;
            return;
        }

        depth++;
        if (depth < n) {
            dfs(depth, sum + sequence[depth]);
            dfs(depth, sum);
        }
    }
}
