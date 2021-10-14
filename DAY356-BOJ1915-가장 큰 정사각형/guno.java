import java.io.*;
import java.util.*;
import java.util.stream.Stream;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }
    static void newSt() throws IOException {st = new StringTokenizer(br.readLine());}

    public static void main(String[] args) throws Exception {
        newSt();
        int n = getInt(), m = getInt();
        boolean[][] map = new boolean[n][m];
        boolean isOneExist = false;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                char a =  s.charAt(j);
                if (a == '1') {
                    isOneExist = true;
                    map[i][j] = true;
                }
            }
        }
        if (!isOneExist) {
            System.out.println(0);
            return;
        }

        int len = 1;
        boolean isFind = false;
        while (true) {
            isFind = false;
            for (int i = 0; i < n - len; i++) {
                for (int j = 0; j < m - len; j++) {
                    if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
                        isFind = true;
                    }else {
                        map[i][j] = false;
                    }
                }
            }
            if(isFind)
                len++;
            else
                break;
        }

        sb.append(len*len);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }


}
