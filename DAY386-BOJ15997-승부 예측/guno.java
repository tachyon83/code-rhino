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

    static class Percent {
        int a, b;
        double w,d,l;
        public Percent(int a, int b, double w, double d, double l) {
            this.a = a;
            this.b = b;
            this.w = w;
            this.d = d;
            this.l = l;
        }
    }
    static Map<String, Integer> map = new HashMap<>();
    static List<Percent> percents = new ArrayList<>();
    static int[] score = new int[4];
    static double[] ans = new double[4];
    public static void main(String[] args) throws Exception {
        getSt();
        for (int i = 0; i < 4; i++) {
            map.put(st.nextToken(), i);
        }
        for (int i = 0; i < 6; i++) {
            getSt();
            int a = map.get(st.nextToken());
            int b = map.get(st.nextToken());
            double w = Double.parseDouble(st.nextToken());
            double d = Double.parseDouble(st.nextToken());
            double l = Double.parseDouble(st.nextToken());
            percents.add(new Percent(a, b, w, d, l));
        }
        dfs(0, 1.0);
        for (double an : ans) {
            sb.append(an).append("\n");
        }

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static public void dfs(int cnt,Double percent) {
        if (cnt == 6) {
            getAns(percent);
            return;
        }
        Percent p = percents.get(cnt);
        score[p.a] += 3;
        dfs(cnt+1,percent*p.w);
        score[p.a] -= 3;

        score[p.a] += 1;
        score[p.b] += 1;
        dfs(cnt+1,percent*p.d);
        score[p.a] -= 1;
        score[p.b] -= 1;

        score[p.b] += 3;
        dfs(cnt+1,percent*p.l);
        score[p.b] -= 3;
    }

    static public void getAns(Double percent) {
        int max = Arrays.stream(score).max().getAsInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            if (score[i] == max) {
                list.add(i);
            }
        }
        if (list.size() == 1) {
            ans[list.get(0)] += percent;
            int second = Arrays.stream(score).filter(i -> i != max).max().getAsInt();
            List<Integer> list2 = new ArrayList<>();
            for (int i = 0; i < 4; i++) {
                if (score[i] == second) {
                    list2.add(i);
                }
            }
            for (Integer i : list2) {
                ans[i] += percent / list2.size();
            }
        } else {
            for (Integer i : list) {
                ans[i] += percent * 2 / list.size();
            }
        }

    }

}
