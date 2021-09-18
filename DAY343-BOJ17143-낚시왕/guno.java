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
    
    static class Shark{
        int s,d,z;

        public Shark(int s, int d, int z) {
            this.s = s;
            this.d = d;
            this.z = z;
        }
    }
    static int R,C;
    public static void main(String[] args) throws Exception {


        st = new StringTokenizer(br.readLine());
        R = getInt(); C = getInt();
        int M = getInt();

        boolean[][] isExist = new boolean[R][C];
        HashMap<Integer,Shark> map = new HashMap<>();
        List<Shark> list = new LinkedList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = getInt(), c = getInt(), s = getInt(), d = getInt(), z = getInt();
            r-=1;c-=1;
            if (d == 1 || d == 2)
                s %= 2 * (R - 1);
            else
                s %= 2 * (C - 1);
            map.put(r*C+c,new Shark(s,d,z));
        }

        int ans = 0;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                int idx = i + j * C;
                if (map.get(idx) != null) {
                    ans+=map.get(idx).z;
                    map.remove(idx);
                    break;
                }
            }
            HashMap<Integer,Shark> temp = new HashMap<>();
            for (Integer idx : map.keySet()) {
                Shark shark = map.get(idx);
                int nextIdx = move(idx, shark);

                Shark existShark = temp.get(nextIdx);
                if (existShark == null || existShark.z<shark.z) {
                    temp.put(nextIdx, shark);
                }

            }
            map = temp;

        }
        sb.append(ans);

        bw.write(sb.toString());bw.flush();bw.close();br.close();
    }

    static int move(int idx,Shark shark){
        int r = idx / C, c = idx % C;
        int s = shark.s, d = shark.d;

        int distToWall = 0;
        int len = (d == 1 || d == 2) ? R - 1 : C - 1;
        switch (d){
            case 1://위
                distToWall = r;
                break;
            case 2: //아래
                distToWall = len - r;
                break;
            case 3://오른
                distToWall = len - c;
                break;
            case 4:
                distToWall = c;
            break;
        }

        if(s<=distToWall){
            switch (d){
                case 1: r-=s;break;
                case 2: r+=s;break;
                case 3: c+=s;break;
                case 4: c-=s;break;
            }
        } else if (s<=distToWall+len) {
            switch (d){
                case 1: r=Math.abs(r-s);break;
                case 2: r=len-(r+s-len);break;
                case 3: c=len-(c+s-len);break;
                case 4: c=Math.abs(c-s);break;
            }
            d = changeDir(d);
        }else{
            switch (d){
                case 1: r+=2*len-s;break;
                case 2: r-=2*len-s;break;
                case 3: c-=2*len-s;break;
                case 4: c+=2*len-s;break;
            }
        }
        shark.d = d;
        return r*C+c;
    }

    static int changeDir(int d){
        switch (d) {
            case 1: return 2;
            case 2: return 1;
            case 3: return 4;
            case 4: return 3;
            default: return 0;
        }
    }
}
