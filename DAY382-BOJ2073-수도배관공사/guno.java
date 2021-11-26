import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb=new StringBuilder();
    static StringTokenizer st;
    static int getInt(){
        return Integer.parseInt(st.nextToken());
    }
    static void getSt() throws IOException {st = new StringTokenizer(br.readLine());}

    static class Pipe {
        int l, c;

        public Pipe(int l, int c) {
            this.l = l;
            this.c = c;
        }
    }

    public static void main(String[] args) throws Exception {
        getSt();
        int d = getInt(), p = getInt();
        List<Pipe> pipes = new ArrayList<>();

        for (int i = 0; i < p; i++) {
            getSt();
            pipes.add(new Pipe(getInt(),getInt()));
        }
        pipes.sort((o1, o2) -> o2.c-o1.c);
        Set<Long> set = new HashSet<>();
        set.add(0L);
        for (Pipe pipe : pipes) {
            List<Long> temp = new ArrayList<>();
            boolean flag = false;
            for (Long num : set) {
                if(pipe.l + num<=d)
                    temp.add(pipe.l + num);
            }
            for (Long l : temp) {
                set.add(l);
                if (l == d) {
                    flag = true;
                }
            }
            if (flag) {
                sb.append(pipe.c);
                break;
            }
        }
        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }
}
