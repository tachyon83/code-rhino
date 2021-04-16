import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ_16928 {

    public static int[] map = new int[101];
    public static int[] diceCount = new int[101];
    public static boolean[] visit = new boolean[101];
    public static int result = 0;

    public static void bfs() {
        Queue<Integer> queue = new LinkedList<>();
        visit[1] = true;
        queue.add(1);

        while(!queue.isEmpty()){
            int playerPosition = queue.remove();
            int count = diceCount[playerPosition];

            if(playerPosition == 100) {
                result = count;
                break;
            }

            int nextPlayerPosition = 0;
            for (int i = 1; i < 7 ; i++) {
                nextPlayerPosition= playerPosition + i;

                if(nextPlayerPosition > 100 ) {
                    continue;
                }

                if(visit[nextPlayerPosition]) {
                    continue;
                }

                visit[nextPlayerPosition] = true;

                if(map[nextPlayerPosition] == 0){
                    diceCount[nextPlayerPosition] = count + 1;
                    queue.add(nextPlayerPosition);
                } else {
                    nextPlayerPosition = map[nextPlayerPosition];
                    if(!visit[nextPlayerPosition]) {
                        visit[nextPlayerPosition] = true;
                        diceCount[nextPlayerPosition] = count + 1;
                        queue.add(nextPlayerPosition);
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);


        for (int i = 0; i < n+m; i++) {
            String[] info = br.readLine().split(" ");
            int start = Integer.parseInt(info[0]);
            int end = Integer.parseInt(info[1]);

            map[start] = end;
        }

        bfs();

        System.out.println(result);
    }
}
