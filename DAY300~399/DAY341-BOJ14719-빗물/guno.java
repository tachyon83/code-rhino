import java.io.*;
import java.util.*;

public class Main {

    static class Pillar{
        int idx,height;

        public Pillar(int idx, int height) {
            this.idx = idx;
            this.height = height;
        }
    }
    static List<Pillar> pillars;
    static int[] heights;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb=new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        heights = new int[w];
        for (int i = 0; i < w; i++) {
            heights[i] = Integer.parseInt(st.nextToken());
        }
        pillars = new LinkedList<>();
        for (int i = 0; i < w - 1; i++) {
            if (heights[i] > heights[i + 1]) {
                pillars.add(new Pillar(i,heights[i]));
            }
        }
        pillars.add(new Pillar(w-1,heights[w-1]));

        pillars.sort((o1, o2) -> o2.height-o1.height);

        int l=pillars.get(0).idx,r=l;
        int ans = 0;

        for (int i = 1; i < pillars.size(); i++) {
            Pillar pillar = pillars.get(i);
            int idx = pillar.idx;
            if (idx < l) {
                ans+=sum(idx,l);
                l = idx;
            }
            if (r < idx) {
                ans += sum(r, idx);
                r = idx;
            }

        }

        sb.append(ans);


        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int sum(int l,int r){
            int height = Math.min(heights[l], heights[r]);
            int sum = 0;
            for (int j = l + 1; j <= r - 1; j++) {
                if (heights[j] < height) {
                    sum += height - heights[j];
                }
            }
            return sum;
    }

}
