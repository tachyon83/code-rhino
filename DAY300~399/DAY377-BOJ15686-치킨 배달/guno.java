import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int getInt() {
        return Integer.parseInt(st.nextToken());
    }

    static void getSt() throws IOException {
        st = new StringTokenizer(br.readLine());
    }

    static int ans=Integer.MAX_VALUE,m;
    static int[] idxs;
    static int houseLen,chickenLen;
    static int[][] dists;
    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }



    public static void main(String[] args) throws Exception {
        getSt();
        int n = getInt();
        m = getInt();
        List<Point> houses = new ArrayList<>();
        List<Point> chickens = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            getSt();
            for (int j = 0; j < n; j++) {
                int num = getInt();
                if (num == 1) {
                    houses.add(new Point(i, j));
                } else if (num == 2) {
                    chickens.add(new Point(i, j));
                }
            }
        }

        houseLen = houses.size();
        chickenLen = chickens.size();
        dists = new int[chickens.size()][houseLen];
        idxs = new int[m];

        for (int i = 0; i < chickenLen; i++) {
            Point chicken = chickens.get(i);
            for (int j = 0; j < houseLen; j++) {
                Point house = houses.get(j);
                dists[i][j] = Math.abs(chicken.x - house.x) + Math.abs(chicken.y - house.y);
            }
        }


        comb(0, 0);
        sb.append(ans);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    static void comb(int s, int cnt) {
        if (cnt == m) {
            ans = Math.min(ans, getAns());
            return;
        }
        for (int i = s; i < chickenLen; i++) {
            idxs[cnt] = i;
            comb(i+1,cnt+1);
        }
    }

    private static int getAns() {
        int[] d = new int[houseLen];
        Arrays.fill(d, Integer.MAX_VALUE);
        for (int idx : idxs) {
            for (int i = 0; i < houseLen; i++) {
                d[i] = Math.min(d[i], dists[idx][i]);
            }
        }
        return Arrays.stream(d).sum();
    }


}
