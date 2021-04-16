// 9663번 N-Queen(gold 5)

// 제출 결과 [메모리: 15012KB 시간: 5764ms]
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ_9663 {
    static int[] map;
    static int n;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            map = new int[n];
            map[0] = i;
            dfs(1);
        }

        System.out.println(count);
    }

    private static void dfs(int depth) {
        if(depth == n){
            count++;
            return;
        }

        for (int i = 0; i < n; i++) {
            map[depth] = i;
            if(possibility(depth)){
                dfs(depth + 1);
            }else {
                map[depth] = 0;
            }
        }
    }

    private static boolean possibility(int depth) {
        for (int i = 0; i < depth; i++) {
            if(map[depth] == map[i])
                return false;
            else if (Math.abs(depth - i) == Math.abs(map[depth] - map[i])) {
                return false;
            }
        }
        return true;
    }
}
